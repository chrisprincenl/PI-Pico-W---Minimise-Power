# PI Pico W - Minimise Power

 The Raspberry PI Pico W is an ideal device as an IoT sensor. It only is succesful when the battery power consumption is minimised. And in particular the Wifi component consumes most of the power. For sensors that require a daily reading, the device doesnt need to be running continuesly.
This code is my experiment/mini project that i work on to create a device that will make the device be on absolutely lowest possible power consumption.
The PI Pico has an RP2040 processor and can get to up to 6mW as minimal power consumption, which isnt very low for modern standards, but there are many ARM microcontrollers out there that can go down to a few uW during (useful) sleep. Just something to keep in mind if one ever considers a project powered by a small battery for professional purposes (mass production). 
 I'm making this publicly available, so that everyone can contribute, or can benefit from my research and experiments. I'll keep this readme document updated with my references (ie links to other material i find on the internet). 

There are three ways:
1) Standard sleep (85.8mW) - The standard RP2040 processor on the raspberry Pi has a sleep_ms function, but all it does is a noop.. So its not saving much power.
2) Deepsleep (32mW) - But the RaspberyPi in GitHub has an (experimental) C library called pico-extras which exports a sleep interface (https://github.com/raspberrypi/pico-extras). It has a function 'sleep_goto_sleep_intil()' which uses the deepsleep interface of the processor and significantly reduces the power consumption.   
3) Dormant mode (6.6mW) - The RP2040 goes dormant until rising clock edge. It basically turns off all external subsystems and depends solely on a clocksource that is stopped. (example code: RP2040_dormant_mode.c)   
 
References:
1) Reddit discussion - https://www.reddit.com/r/raspberrypipico/comments/10ynbz1/power_reduction_on_pico_w_how_to_do/?share_id=A1Owp69ZcpokUhD0NwcIL&utm_content=1&utm_medium=ios_app&utm_name=ioscss&utm_source=share&utm_term=4
2) Youtube video Deep sleep example - https://www.youtube.com/watch?v=05o5QOZkpwg&list=PLNR62dPSpLdvRIKLcb4CTNqBkMeQ5iDyf&index=1
3) External clock - tAdafruit DS1307 Real Time Clock (RTC) Breakout Board Kit (https://uk.pi-supply.com/products/adafruit-ds1307-real-time-clock-rtc-breakout-board-kit?_pos=4&_sid=fb3e48ac4&_ss=r)
4) External clock wake up PI -  https://github.com/bablokb/pi-wake-on-rtc
5) https://forums.raspberrypi.com/viewtopic.php?t=206548
6) tpl5110 - https://www.distrelec.nl/nl/tpl5110-nano-stroomtimer-sparkfun-electronics-prt-15353/p/30157553?cq_src=google_ads&cq_cmp=18200849884&cq_con=&cq_term=&cq_med=pla&cq_plac=&cq_net=x&cq_pos=&cq_plt=gp&gad_source=1&gclid=CjwKCAiAvoqsBhB9EiwA9XTWGbLc1UB6q1j-oCLuHrHA9A4DZXO_XrK0hHadt9Ac-OWBHPST0NSqWxoC7gwQAvD_BwE&gclsrc=aw.ds
7) https://github.com/elehobica/pico_battery_op/
8) Raspberry pi pico datasheet - https://datasheets.raspberrypi.com/pico/pico-datasheet.pdf
