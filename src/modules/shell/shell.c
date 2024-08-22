#include "shell.h"

LOG_MODULE_REGISTER(app);

Simon_t simon;

void shell_set_simon(simon_says_opt_t opt)
{
	simon.user_opt = opt;
}

simon_says_opt_t shell_is_simon_enabled(void)
{
	return simon.user_opt;
}

static int shell_cmd_simon_enable_handler(const struct shell *shell, size_t argc, char **argv)
{
	if ( argc != MINIMUM_MANDATORY_ENABLE_OPTIONS ){
		shell_print(shell, "There must be 1 input (1 or 0). Try again.");
		return -1;
	}

	const simon_says_opt_t NEW_STATE = atoi(argv[1]) == 1 ? ENABLED : DISABLED;
	shell_set_simon(NEW_STATE);
	shell_print(shell, "Simon Says %s.", NEW_STATE == ENABLED ? "Enabled" : "Disabled");

    return 0;
}

SHELL_CMD_ARG_REGISTER(simon_enable, 
	NULL, 
	"By default, Simon Says is disabled, but you can enable it with a <1/0> input", 
	shell_cmd_simon_enable_handler, 
	MINIMUM_MANDATORY_ENABLE_OPTIONS, 
	MINIMUM_OPTIONAL_ENABLE_OPTIONS);