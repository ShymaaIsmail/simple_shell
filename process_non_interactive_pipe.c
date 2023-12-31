#include "main.h"

/**
* process_non_interactive_pipe - process command in non interactive pipe
* @program_name: name of the program to handles errors
* @exit_code: the exit code of the function
* Return: Void
*/
void process_non_interactive_pipe(char *program_name, int *exit_code)
{
	char *input;
	char buffer[(BUFFER_SIZE * 10) + 1];
	ssize_t input_data_size;
	char ***commands;

	input_data_size = read(STDIN_FILENO, buffer, BUFFER_SIZE * 10);
	if (input_data_size > 0)
	{
		input = malloc(input_data_size + 1);
		if (input != NULL)
		{
			buffer[input_data_size] = '\0';
			str_cpy(input, buffer);
			commands = extract_tokens(input);
			if (commands != NULL && program_name != NULL)
			{
				execute_command(input, program_name, commands, exit_code);
			}
			free(input);
		}
	}
}
