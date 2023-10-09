#include "main.h"

/**
* main - main
* @ac: d
* @argv: f
* Return: int
*/
int main(int ac, char **argv)
{
	int shell_mode = check_mode(ac);
	int *exit_code = malloc(sizeof(int));
	int exit_success = EXIT_SUCCESS;

	exit_code = &exit_success;
	if (shell_mode == INTERACTIVE_INPUT)
	{
		display_user_prompt(argv, exit_code);
	}
	else if (shell_mode == FILE_INPUT)
	{
		process_non_interactive_file(argv, exit_code);
	}
	else if (shell_mode == PIPE_INPUT)
	{
		process_non_interactive_pipe(argv[0], exit_code);
	}
	return (*exit_code);
}
