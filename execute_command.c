#include "main.h"
/**
 * execute_command - execute_command
 * @program_name: program name
 * @argv: 2 d array for user input
*/
void execute_command(char *program_name, char **argv)
{
		int index = 0;
		/*SHELL_ERORR not_found_command = {NOT_FOUND_COMMAND, NULL};*/

		while (argv[index] != NULL && program_name != NULL)
		{
			printf("%s\n", argv[index]);
			index++;
		}


		/* just for testing print error*/
		/**
		 * print_shell_error(not_found_command, 2, program_name, "biin");
		*print_shell_error(not_found_command, 0);
		*/

}
