#include <zephyr/kernel.h>
#include "modules/led/led.h"
#include "modules/button/button.h"
#include "modules/shell/shell.h"

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)
#define LED2_NODE DT_ALIAS(led2)
#define LED3_NODE DT_ALIAS(led3)

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */

static const struct gpio_dt_spec leds[4] =
{
	GPIO_DT_SPEC_GET(LED0_NODE, gpios),
	GPIO_DT_SPEC_GET(LED1_NODE, gpios),
  GPIO_DT_SPEC_GET(LED2_NODE, gpios),
	GPIO_DT_SPEC_GET(LED3_NODE, gpios),
};

static const gpio_flags_t pins_flag[4] = {
	GPIO_OUTPUT_INACTIVE,
	GPIO_OUTPUT_INACTIVE,
  GPIO_OUTPUT_INACTIVE,
  GPIO_OUTPUT_INACTIVE
};


/*
 * Get button configuration from the devicetree sw0 alias. This is mandatory.
 */
#define SW0_NODE DT_ALIAS(sw0)
#if !DT_NODE_HAS_STATUS(SW0_NODE, okay)
#error "Unsupported board: sw0 devicetree alias is not defined"
#endif

#define SW1_NODE DT_ALIAS(sw1)
#if !DT_NODE_HAS_STATUS(SW1_NODE, okay)
#error "Unsupported board: sw1 devicetree alias is not defined"
#endif

#define SW2_NODE DT_ALIAS(sw2)
#if !DT_NODE_HAS_STATUS(SW2_NODE, okay)
#error "Unsupported board: sw2 devicetree alias is not defined"
#endif

#define SW3_NODE DT_ALIAS(sw3)
#if !DT_NODE_HAS_STATUS(SW3_NODE, okay)
#error "Unsupported board: sw3 devicetree alias is not defined"
#endif

static const struct gpio_dt_spec buttons[4] = {
	GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios, {0}),
	GPIO_DT_SPEC_GET_OR(SW1_NODE, gpios, {0}),
	GPIO_DT_SPEC_GET_OR(SW2_NODE, gpios, {0}),
	GPIO_DT_SPEC_GET_OR(SW3_NODE, gpios, {0})};

static const gpio_flags_t buttons_flag[4] = {
	GPIO_INPUT,
	GPIO_INPUT,
  GPIO_INPUT,
  GPIO_INPUT
};

static const gpio_flags_t buttons_interruption_flag[4] = {
	GPIO_INT_EDGE_TO_ACTIVE,
	GPIO_INT_EDGE_TO_ACTIVE,
  GPIO_INT_EDGE_TO_ACTIVE,
  GPIO_INT_EDGE_TO_ACTIVE
};


static struct gpio_callback button_cb_data[4];