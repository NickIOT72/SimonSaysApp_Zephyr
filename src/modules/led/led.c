#include "led.h"

int led_initMultiple(const struct gpio_dt_spec *leds, uint8_t size )
{
  int ret = -1;
  int ret2 = -1;

  for(  int i = 0; i < size; i++ )
  {
    if (!gpio_is_ready_dt( &leds[i]) ) {
      ret2 = 0;
	  	break;
	  }

	  ret = gpio_pin_configure_dt(&leds[i], GPIO_OUTPUT_ACTIVE);
	  if (ret < 0) {
	  	ret2 = 0;
	  	break;
	  }
  }
	
  return ret2;
}

int led_init(const struct gpio_dt_spec *led , const gpio_flags_t pin_flag)
{
  int ret = 0;
  int ret2 = 0;

  if (!gpio_is_ready_dt(led) ) {
    ret2 = -1;
	}
	ret = gpio_pin_configure_dt(led, pin_flag);
	if (ret < 0) {
		ret2 = -2;
	}
  return ret2;
}

int led_toogle(const struct gpio_dt_spec *led)
{
  return gpio_pin_toggle_dt(led);
}	

int led_ON(const struct gpio_dt_spec *led)
{
  return gpio_pin_set_dt(led, 1);
}
int led_OFF(const struct gpio_dt_spec *led)
{
  return gpio_pin_set_dt(led, 0);
}
int led_readLed(const struct gpio_dt_spec *led)
{
  return gpio_pin_get_dt(led);
}