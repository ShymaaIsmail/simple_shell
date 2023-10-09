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

	if (command[param])
	{
		r = stoi(command[1]);
		if (r < 0)
			r = 2;
		free_matrix(command);
		exit(r);
	}
	free_matrix(command);
	exit(EXIT_SUCCESS);
}
