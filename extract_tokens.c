#include "main.h"
/**
* extract_tokens - extract_tokens
* @chars_count: count of chars entered by a user
* @user_input_ptr: pointer to content entered by a user
* Return: 2 dimensional array of all commands lines
* and arguments written by the user
*/
char ***extract_tokens(int chars_count, char *user_input_ptr)
{
	char *user_input_ptr_copy = malloc(sizeof(char) * (chars_count + 1));
	char  ***argv = NULL, *rows_token, *columns_token;
	char *rows_token_copy, *columns_token_copy;
	size_t rows_count = 0, columns_count = 0, i, j = 0;

	if (user_input_ptr_copy != NULL)
	{
		strcpy(user_input_ptr_copy, user_input_ptr);
		printf("user_input_ptr_copy %s\n", user_input_ptr_copy);
		rows_token = strtok(user_input_ptr_copy, New_Line_Delim);
		printf("rows_token %s\n", rows_token);
		while (rows_token != NULL)
		{
			columns_count = 0;
			rows_token_copy = str_dup(rows_token);
			printf("rows_token_copy %s\n", rows_token_copy);
			columns_token = strtok(rows_token_copy, Space_Delim);
			columns_token_copy = str_dup(columns_token);
			while (columns_token_copy != NULL)
			{
				printf("columns_token %s\n", columns_token_copy);
				columns_token_copy = strtok(NULL, Space_Delim);
				columns_count++;
			}
			printf("columns_count %d\n", (int)columns_count);
			rows_token = strtok(NULL, New_Line_Delim);
			printf("rows_token %s\n", rows_token);
			rows_count++;
		}
		printf("rows_count %d\n", (int)rows_count);
		argv = (char ***)malloc((rows_count + 1) * sizeof(char *));
		/*if (argv != NULL)
		{
			for (i = 0; i < rows_count ; i++)
			{
				argv[i] = malloc(columns_count * sizeof(char *));
			}
			rows_token = strtok(user_input_ptr, New_Line_Delim);
			i = 0;
			while (rows_token != NULL)
			{
				columns_token = strtok(rows_token, Space_Delim);
				j = 0;
				while (columns_token != NULL)
				{
					argv[i][j] = malloc((strlen(columns_token) + 1) * sizeof(char *));
					str_cpy(argv[i][j], columns_token);
					j++;
					columns_token = strtok(NULL, Space_Delim);
				}
				argv[i][j] = NULL;
				i++;
				rows_token = strtok(NULL, New_Line_Delim);
			}
			argv[rows_count] = NULL;
		}*/
	}
	return (argv);
}
