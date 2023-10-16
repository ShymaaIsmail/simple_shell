#include "main.h"

/**
 *  execute_env - prints local environment variables, hanle command "env"
 * @exit_code: the exit status that the program will terminate with
 * Return: void
*/
void execute_env(int *exit_code)
{
	char **current_local_env = environ;

	while (*current_local_env != NULL)
	{
		write(STDOUT_FILENO, *current_local_env, str_len(*current_local_env));
		write(STDOUT_FILENO, "\n", 1);
		current_local_env++;
	}
	*exit_code = EXIT_SUCCESS;
}
