/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "main.h"

#define SLEEP_TIME_MS   1000

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
