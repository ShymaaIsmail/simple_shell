#include "main.h"

/**
 * get_line_number - get_line_number
 * @line_index: line_index
 * Return: stringified line number
*/
int get_line_number(int line_index)
{
	return (line_index + 1);
}
/**
* process_command - execute_command
* @argv: 2 d array for user input
* Return: int
*/
int process_command(char **argv)
{
	int exit_code;
	char *command;
	pid_t child_pid;
	int status;

	command = validate_command(argv[0]);
	if (command)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			exit(EXIT_ERROR);
		}
		else if (child_pid == 0)
		{
			exit_code = execve(command, argv, environ);
			if (exit_code == -1)
			{
				perror("execve");
				exit(exit_code);
			}
			}
		else
		{
			waitpid(child_pid, &status, 0);
			if (WIFEXITED(status))
			{
			exit_code = WEXITSTATUS(status);
			if (exit_code != 0)
			{
				exit_code =  2;
			}
			}
			else
			{
				exit_code = 3;
			}
		}
	}
	return (exit_code);
}

/**
* execute_command - execute_command
* @program_name: program name
* @argv: 2d array for user input
* @exit_code: exit code
*/
void execute_command(char *program_name, char ***argv, int *exit_code)
{
		int line_index;

		char *command;

		if (argv != NULL && program_name != NULL)
		{
			for (line_index = 0; argv[line_index] != NULL; line_index++)
			{

				command = argv[line_index][0];
				if (str_cmp(command, EXIT) == 0)
				{
					*exit_code = execute_exit(argv[line_index], program_name,
												get_line_number(line_index), *exit_code);
				}
				else if (str_cmp(command, ENV) == 0)
				{
					execute_env(exit_code);
				}
				else
				{
					*exit_code = process_command(argv[line_index]);
				}
			}
		}
}
