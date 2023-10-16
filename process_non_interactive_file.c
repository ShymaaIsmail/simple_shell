#include "main.h"

/**
 *  process_non_interactive_file - process command in the non interactive mode
 * @argv: array of arguments
 * @exit_code: the exit code of the function
*/
void process_non_interactive_file(char **argv, int *exit_code)
{
	printf(" file name is %s %d \n", argv[1], *exit_code);
}
