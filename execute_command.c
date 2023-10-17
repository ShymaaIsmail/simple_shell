#include "main.h"

/**
 * get_line_number - get the index of the enterd command in the shell
 * @line_index: th index of the line
 * Return: stringified line number (Int)
*/
int get_line_number(int line_index)
{
	return (line_index + 1);
}
/**
* process_command - It hansles the "validate_command" and processes it
* @argv: 2 d array for user input
* @program_name: the name of the program for handlig errors
* @line_number: index of the command in the shell
* Return: integer
*/
int process_command(char **argv, char *program_name, int line_number)
{
	int exit_code, status;
	char *command;
	pid_t child_pid;

	command = validate_command(argv[0]);
	if (command)
	{
		child_pid = fork();
		if (child_pid == -1)
			exit(EXIT_ERROR);
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
					exit_code =  2;
			}
			else
					exit_code = 3;
		}
	}
	else
	{
		print_shell_error((enum ERROR_CODE)NOT_FOUND, 3, program_name,
							line_number, argv[0]);
		exit_code =  EXIT_COMMAND_NOTFUND;
	}
	return (exit_code);
}

/**
* execute_command - executes all commands that passed to the shell
* @program_name: the name of the program for handlig errors
* @argv: 2d array for user input
* @exit_code: the exit code the function will terminate with
* @input: input
* Return: Void
*/
void execute_command(char *input, char *program_name, char ***argv,
					int *exit_code)
{
		int line_index;

		char *command;

		if (argv != NULL && program_name != NULL)
		{
			for (line_index = 0; argv[line_index] != NULL; line_index++)
			{

				command = argv[line_index][0];
				if (command != NULL)
				{
				if (str_cmp(command, EXIT) == 0)
				{
					*exit_code = execute_exit(input, argv, argv[line_index], program_name,
												get_line_number(line_index), *exit_code);
				}
				else if (str_cmp(command, ENV) == 0)
				{
					execute_env(exit_code);
				}
				else
				{
					*exit_code = process_command(argv[line_index], program_name,
													get_line_number(line_index));
				}
				}
			}
			free_tokens(argv);
		}
}
