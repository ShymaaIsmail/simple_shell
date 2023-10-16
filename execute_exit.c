#include "main.h"

/**
 * execute_exit - function that apply the exit of the shell
 * @command: the command that will be excuted (exit with or with out args)
 * @program_name: program name to hanle error message
 * @line_number: line index of the command
 * @previous_error_code: error code of the previous error
 * @argv:  pointer to 2D array argument
 * @input: input of the user (command)
 * Return: (void) no value will be returned
*/
int execute_exit(char *input, char ***argv, char **command, char *program_name,
					int line_number, int previous_error_code)
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
		free(input);
		free_tokens(argv);
		exit(r);
	}
	if (previous_error_code == 0 || (isatty(STDIN_FILENO)
			&& previous_error_code > 0))
	{
		free(input);
		free_tokens(argv);
		exit(EXIT_SUCCESS);
	}
	else
	{
		return (previous_error_code);
	}
}
