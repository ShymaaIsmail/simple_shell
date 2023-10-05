#include "main.h"
/**
 * execute_command - execute_command
*/
void execute_command(char *program_name, char **argv)
{
		SHELL_ERORR not_found_command = {NOT_FOUND_COMMAND, NULL};


		/* just for testing print error*/
		print_shell_error(not_found_command, 2, "loy", "biin");
		print_shell_error(not_found_command, 0);

}
