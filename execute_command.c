#include "main.h"

/**
* process_command - execute_command
* @argv: 2 d array for user input
*/
void process_command(char **argv)
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
		}
		else if (child_pid == 0)
		{
			execvp(command, argv);
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
}
/**
* execute_command - execute_command
* @program_name: program name
* @argv: 2 d array for user input
*/
void execute_command(char *program_name, char ***argv)
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
					execute_exit();
				}
				else if (str_cmp(command, ENV) == 0)
				{
					execute_env();
				}
				else
				{
					process_command(argv[line_index]);
				}
			}
		}

		/* just for testing print error*/
		/**
		 * print_shell_error(not_found_command, 2, program_name, "biin");
		*print_shell_error(not_found_command, 0);
		*/

}
