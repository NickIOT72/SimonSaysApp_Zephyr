#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <zephyr/drivers/gpio.h>

int button_init(const struct gpio_dt_spec *btn , const gpio_flags_t pin_flag);
int button_read(const struct gpio_dt_spec *btn);


#endif