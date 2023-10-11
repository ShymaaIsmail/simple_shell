#include "main.h"

/**
 * execute_exit - function that apply the exit of the shell
 * @command: the command that will be excuted
 * @program_name: program_name
 * @line_number: line_number
 * @previous_error_code: previous_error_code
 * Return: (void) no return value
*/
int execute_exit(char **command, char *program_name, int line_number,
				int previous_error_code)
{
	int first_arg = 1;
	int command_index = 0;
	int r;

	if (command[first_arg])
	{
		r = stoi(command[first_arg]);
		if (r == -1)
		{
			r = 2;
			print_shell_error((enum ERROR_CODE)ILLEGAL_PARAMETER, 4, program_name,
								line_number, command[command_index], command[first_arg]);
			return (r);
		}
		free_matrix(command);
		exit(r);
	}
	free_matrix(command);
	if (previous_error_code == 0 || (isatty(STDIN_FILENO)
			&& previous_error_code > 0))
	{
		exit(EXIT_SUCCESS);
	}
	{
		return (previous_error_code);
	}
}
