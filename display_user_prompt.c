#include "main.h"

/**
* display_user_prompt - display_user_prompt
* @argv: array of pointers with args
* Return: void
*/
void display_user_prompt(char **argv)
{
	ssize_t chars_count;
	char *user_input_ptr;
	size_t n = 0;
	char *program_name = argv[0];

	while (1)
	{
		write(STDOUT_FILENO, Prompt_Title, 2);
		chars_count = getline(&user_input_ptr, &n, stdin);
		if (chars_count == EOF)
		{
			execute_eof();
		}
		else if (chars_count == SIGINT)
		{
			execute_signal_interupt();
		}
		argv = extract_tokens(chars_count, user_input_ptr);
	}
	free_all(2, &user_input_ptr, &argv);
}
