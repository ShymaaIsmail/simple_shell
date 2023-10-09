#include "main.h"

/**
 * execute_exit - function that apply the exit of the shell
 * @command: the command that will be excuted
 * Return: (void) no return value
*/
void execute_exit(char **command)
{
	int param = 1;
	int r;
	SHELL_ERORR parameter_illegal = {ILLEGAL_PARAMETER, NULL};
       	
	if (command[param])
	{
		r = stoi(command[param]);
		if (r == -1)
		{
			r = 2;
			print_shell_error(parameter_illegal, 2, "exit", command[param]);
		}
		free_matrix(command);
		exit(r);
	}
	free_matrix(command);
	exit(EXIT_SUCCESS);
}
