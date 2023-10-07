#include "main.h"

/**
* check_mode - determine whether the shell
* usage mode interactive or not
* @ac: arguments count
* Return: 1 or 0
*/
int check_mode(int ac)
{
	int mode = INTERACTIVE_INPUT;

	if (!isatty(STDIN_FILENO) && ac == 1)
	{
		mode = PIPE_INPUT;
	}
	else if (!isatty(STDIN_FILENO) && ac > 1)
	{
		mode = FILE_INPUT;
	}
	return (mode);
}
