#include "main.h"

/**
* display_user_prompt - display_user_prompt
* @argv: array of pointers with args
* @exit_code: exit_code
* Return: void
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
			execute_command(program_name, commands, exit_code);
		}
	}
	free_all(2, &user_input_ptr, &argv);
}
