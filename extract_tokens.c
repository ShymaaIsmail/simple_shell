#include "main.h"
/**
* extract_tokens - extract_tokens
* @chars_count: count of chars entered by a user
* @user_input_ptr: pointer to content entered by a user
* Return: 2 dimensional array of all commands lines
* and arguments written by the user
*/
char **extract_tokens(int chars_count, char *user_input_ptr)
{
	char *user_input_ptr_copy = malloc(sizeof(char) * (chars_count + 1));
	char  **argv = NULL, *rows_token, *columns_token, *temp;
	size_t rows_count = 0, columns_count = 0, i = 0, row_length = 0;

	if (user_input_ptr_copy != NULL)
	{
		strcpy(user_input_ptr_copy, user_input_ptr);
		rows_token = strtok(user_input_ptr_copy, New_Line_Delim);
		while (rows_token != NULL)
		{
			rows_count++;
			rows_token = strtok(NULL, New_Line_Delim);
		}
		argv = malloc(sizeof(char *) * (rows_count + 1));
		if (argv != NULL)
		{
			rows_token = strtok(user_input_ptr, New_Line_Delim);
			i = 0;
			while (rows_token != NULL)
			{
				row_length = str_len(rows_token);
				argv[i] = malloc(sizeof(char) * (row_length + 1));
				if (argv[i] != NULL)
				{
					str_cpy(argv[i], rows_token);
					columns_token = strtok(argv[i], Space_Delim);
					columns_count = str_len(columns_token);
					temp = malloc(sizeof(char) * (columns_count + 1));
					str_cpy(temp, columns_token);
					temp[columns_count] = '\0';
					argv[i] = temp;
					rows_token = strtok(NULL, New_Line_Delim);
					i++;
					free_all(1, &temp);
				}
			}
			argv[i] = NULL;
		}
	}
	return (argv);
}
