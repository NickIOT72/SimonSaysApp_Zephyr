#ifndef __LED_H__
#define __LED_H__

#include <zephyr/drivers/gpio.h>

int led_init(const struct gpio_dt_spec *led , const gpio_flags_t pin_flag);
int led_initMultiple(const struct gpio_dt_spec *leds, uint8_t size );
int led_toogle(const struct gpio_dt_spec *led);
int led_ON(const struct gpio_dt_spec *led);
int led_OFF(const struct gpio_dt_spec *led);
int led_readLed(const struct gpio_dt_spec *led);

#endif