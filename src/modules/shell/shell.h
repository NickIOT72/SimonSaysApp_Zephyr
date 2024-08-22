#ifndef _SHELL_H_
#define _SHELL_H_
#include <zephyr/shell/shell.h>
#include <zephyr/logging/log.h>
#include <stdlib.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/usb/usb_device.h>
#include <ctype.h>

#define MINIMUM_MANDATORY_ENABLE_OPTIONS 2
#define MINIMUM_OPTIONAL_ENABLE_OPTIONS 0

typedef enum {
    DISABLED,
    ENABLED
} simon_says_opt_t;

typedef struct Simon_t
{
    simon_says_opt_t user_opt;
} Simon_t;

void shell_set_simon(simon_says_opt_t opt);
simon_says_opt_t shell_is_simon_enabled(void);

#endif