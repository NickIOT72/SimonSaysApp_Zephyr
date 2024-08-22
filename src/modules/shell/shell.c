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

SHELL_CMD_ARG_REGISTER(simon_enable, 
	NULL, 
	"By default, Simon Says is disabled, but you can enable it with a <1/0> input", 
	shell_cmd_simon_enable_handler, 
	MINIMUM_MANDATORY_ENABLE_OPTIONS, 
	MINIMUM_OPTIONAL_ENABLE_OPTIONS);