#include "main.h"

/**
* main - main (the start point of execute program)
* @ac: d
* @argv: pointer to 2d array
* Return: integer
*/
int main(int ac, char **argv)
{
	int shell_mode = check_mode(ac);
	int exit_code = EXIT_SUCCESS;

	if (shell_mode == INTERACTIVE_INPUT)
	{
		display_user_prompt(argv, &exit_code);
	}
	else if (shell_mode == FILE_INPUT)
	{
		process_non_interactive_file(argv, &exit_code);
	}
	else if (shell_mode == PIPE_INPUT)
	{
		process_non_interactive_pipe(argv[0], &exit_code);
	}
	return (exit_code);
}
