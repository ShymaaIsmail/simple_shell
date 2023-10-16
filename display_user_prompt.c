#include "main.h"

/**
* display_user_prompt - it display the user prompt that appear in the shell "$"
* @argv: array of pointers with arguments
* @exit_code: the exit_code that function will be terminated with
* Return: void (Return Nothing)
*/
void display_user_prompt(char **argv, int *exit_code)
{
	ssize_t chars_count;
	char *user_input_ptr = NULL;
	size_t n = 0;
	char *program_name = argv[0];
	char ***commands;

	while (1)
	{
		write(STDOUT_FILENO, Prompt_Title, 2);
		chars_count = getline(&user_input_ptr, &n, stdin);
		if (chars_count == EOF)
		{
			execute_eof();
		}
		commands = extract_tokens(user_input_ptr);
		if (commands != NULL)
		{
			execute_command(user_input_ptr, program_name, commands, exit_code);
		}
	}
	free_all(2, &user_input_ptr, &argv);
}
