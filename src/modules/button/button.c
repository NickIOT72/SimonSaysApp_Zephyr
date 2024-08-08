#include "button.h"

int button_init(const struct gpio_dt_spec *btn , const gpio_flags_t pin_flag)
{
  int ret = 0;
  if (!device_is_ready(btn->port))
	{
		return -1;
	}

  ret = gpio_pin_configure_dt(btn, pin_flag);
  if (ret < 0) {
    return ret;
  }

  return ret;
}

int button_read(const struct gpio_dt_spec *btn)
{
  return gpio_pin_get_dt(btn);
}

