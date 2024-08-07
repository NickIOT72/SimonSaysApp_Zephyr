#include <zephyr/kernel.h>
#include "modules/led/led.h"

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec leds[2] =
{
	GPIO_DT_SPEC_GET(LED0_NODE, gpios),
	GPIO_DT_SPEC_GET(LED1_NODE, gpios)
};

static const gpio_flags_t pins_flag[2] = {
	GPIO_OUTPUT_INACTIVE,
	GPIO_OUTPUT_INACTIVE
};
