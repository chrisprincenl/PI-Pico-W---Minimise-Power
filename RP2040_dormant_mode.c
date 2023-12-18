#include ‹stdio.h>
#include "pico/stdlib.h"
#include "pico/sleep.h"

#include "hardware/rtc.h"

#define LED_PIN 25
#define WAKE_PIN 10

int main() {
	stdio_init_all();

	gpio_init(LED_PIN);

	gpio_set_dir(WAKE_PIN, GPTO_IN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	sleep_run_from_xosc();

	sleep goto_dormant_until_edge_high(WAKE_PIN);

	gpio_put (LED_PIN, 1);
	while (1) {
		tight_loop_contents();
	}

	return 0;
}
