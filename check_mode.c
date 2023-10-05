#include "main.h"

/**
* check_mode - determine whether the shell
* usage mode interactive or not
* Return: 1 or 0
*/
int check_mode(void)
{
	return (isatty(STDIN_FILENO));
}
