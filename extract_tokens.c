#include "main.h"
/**
* extract_tokens - extract_tokens
* @chars_count: count of chars entered by a user
* @user_input_ptr: pointer to content entered by a user
* Return: pointer of pointer to an array to words of user input
*/
char **extract_tokens(int chars_count, char *user_input_ptr)
{
		char **argv;
		char *user_input_ptr_copy = malloc(sizeof(char) * chars_count);
		char *token;
		size_t num_tokens = 0, i = 0;

		if (user_input_ptr_copy != NULL)
		{
			strcpy(user_input_ptr_copy, user_input_ptr);
			token = strtok(user_input_ptr, Command_DeLim);
			while (token != NULL)
			{
			num_tokens++;
			token = strtok(NULL, Command_DeLim);
			}
			num_tokens++;
			argv = malloc(sizeof(char *) * num_tokens);
			if (argv != NULL)
			{
				token = strtok(user_input_ptr_copy, Command_DeLim);

				for (i = 0; token != NULL; i++)
				{
				argv[i] = malloc(sizeof(char) * strlen(token));
				strcpy(argv[i], token);
				token = strtok(NULL, Command_DeLim);
				}
				argv[i] = NULL;
				free_all(1, &user_input_ptr_copy);
			}
		}
	return (argv);
}
