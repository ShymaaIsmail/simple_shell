#include "main.h"

/**
* process_non_interactive_pipe - process_non_interactive_pipe
* @program_name: program_name
*/
void process_non_interactive_pipe(char *program_name)
{
	char *input;
	char buffer[(BUFFER_SIZE * 2) + 1];
	ssize_t input_data_size;
	char ***commands;

	input_data_size = read(STDIN_FILENO, buffer, BUFFER_SIZE * 2);
	if (input_data_size > 0)
	{
		input = malloc(input_data_size + 1);
		if (input != NULL)
		{
			buffer[input_data_size] = '\0';
			str_cpy(input, buffer);
			commands = extract_tokens(input_data_size, input);
			if (commands != NULL && program_name != NULL)
			{
				execute_command(program_name, commands);
			}
		}
	}
}
