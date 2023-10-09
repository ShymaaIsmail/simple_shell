#include "main.h"

/**
* process_command - execute_command
* @argv: 2 d array for user input
* @exit_code: exit_code
*/
void process_command(char **argv, int *exit_code)
{
	char *command;
	pid_t child_pid;
	int status;
	/**
	 * to do zainab
	*/
	command = validate_command(argv[0]);
	if (command)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork failed");
			exit(EXIT_ERROR);
		}
		else if (child_pid == 0)
		{
			execve(command, argv, NULL);
			perror("execve");
			exit(EXIT_ERROR);
		}
		else
		{
			waitpid(child_pid, &status, WUNTRACED);
			*exit_code  = WEXITSTATUS(status);
		}
	}
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
					/**
					 * to do zainab
					*/
					execute_exit(argv[line_index]);
				}
				else if (str_cmp(command, ENV) == 0)
				{
					execute_env();
				}
				else
				{
					process_command(argv[line_index], exit_code);
				}
			}
		}

		/* just for testing print error*/
		/**
		 * print_shell_error(not_found_command, 2, program_name, "biin");
		*print_shell_error(not_found_command, 0);
		*/

}
