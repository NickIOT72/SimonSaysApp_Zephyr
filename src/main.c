/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "main.h"

#define SLEEP_TIME_MS   1000

void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
  uint32_t bit_to_pin = 0;
	for (int i = 0; i < 32; i++) {
		if ((pins >> i) == 1) {
			bit_to_pin = i;
			break;
		}
	}
	if( bit_to_pin == 0 ) return;

	printk("pin %d interrupted at %llu\n", bit_to_pin, k_uptime_get());
}

int button_setUpInterruption( const struct gpio_dt_spec *btn , const gpio_flags_t pin_flag, struct gpio_callback *btn_cb_data  )
{
	int ret = 0;

	ret = gpio_pin_interrupt_configure_dt(btn, pin_flag);
	if (ret < 0) {
		return 0;
	}

	gpio_init_callback(btn_cb_data, button_pressed  , BIT(btn->pin));

	gpio_add_callback(btn->port, btn_cb_data);
	
	return ret;
}

int main(void)
{
	int ret;
	int leds_total = sizeof(leds)/sizeof(leds[0]);

	for(int i = 0; i <  leds_total; i++)
	{
		ret = led_init(&leds[i], pins_flag[i]);
		if (ret < 0) {
	  	return 0;
	  }
		printk("Set up LED at %s pin %d\r\n", leds[i].port->name, leds[i].pin);

		ret = button_init(&buttons[i], buttons_flag[i]);
		if (ret < 0) {
	  	return 0;
	  }

		ret = button_setUpInterruption( &buttons[i] , buttons_interruption_flag[i],  &button_cb_data[i] );
		if (ret < 0) {
	  	return 0;
	  }
		printk("Set up button at %s pin %d\r\n", buttons[i].port->name, buttons[i].pin);
	}

	while (1) {
		for( int i = 0; i < leds_total; i++ ) {	
			ret = led_ON(&leds[i]);
      if (ret < 0) {
        return 0;
      }
      k_msleep(SLEEP_TIME_MS);
			ret = led_OFF(&leds[i]);
      if (ret < 0) {
        return 0;
      }
      k_msleep(SLEEP_TIME_MS);
		}
	}
	return 0;
}
