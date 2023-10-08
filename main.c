#include "main.h"

/**
* main - main
* @ac: d
* @argv: f
* Return: int
*/
int main(int ac, char **argv)
{
	int exit_code = EXIT_SUCCESS;
	int shell_mode = check_mode(ac);

	if (shell_mode == INTERACTIVE_INPUT)
	{
		display_user_prompt(argv);
	}
	else if (shell_mode == FILE_INPUT)
	{
		process_non_interactive_file(argv);
	}
	else if (shell_mode == PIPE_INPUT)
	{
		process_non_interactive_pipe(argv[0]);
	}
	return (exit_code);
}
