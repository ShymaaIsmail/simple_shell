#include "main.h"


/**
 * get_rows_count - get_rows_count
 * @input: input
 * Return: int
*/
size_t get_rows_count(char *input)
{
	size_t rows_count = 0;
	char *rows_token;
	char *temp_input = str_dup(input);

	rows_token = strtok(temp_input, New_Line_Delim);
	while (rows_token != NULL)
	{
		rows_count++;
		rows_token = strtok(NULL, New_Line_Delim);
	}
	return (rows_count);
}

/**
 * get_columns_count_by_row_index - get_columns_count_by_row_index
 * @input: input
 * @row_index: row_index
 * Return: int
*/
size_t get_columns_count_by_row_index(char *input, size_t row_index)
{
	size_t column_count = 0;
	char *token;
	size_t current_row = 0;
	char *copy_input = str_dup(input);

	token = strtok(copy_input, New_Line_Delim);
	while (token != NULL && current_row < row_index)
	{
		token = strtok(NULL, New_Line_Delim);
		current_row++;
	}
	if (token != NULL)
	{
		token = strtok(token, Space_Delim);
		while (token != NULL)
		{
			column_count++;
			token = strtok(NULL, Space_Delim);
		}
	}
	return (column_count);
}
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
	size_t rows_count = 0, columns_count = 0, row_index, i, j = 0;

	if (user_input_ptr_copy != NULL)
	{
		user_input_ptr_copy = str_dup(user_input_ptr);
		rows_count = get_rows_count(user_input_ptr_copy);
		argv = (char ***)malloc((rows_count + 1) * sizeof(char *));
		if (argv != NULL)
		{
			for (row_index = 0; row_index < rows_count ; row_index++)
			{
				columns_count = get_columns_count_by_row_index
									(user_input_ptr_copy, row_index);
				argv[row_index] = malloc(columns_count * sizeof(char *));
			}
			rows_token = strtok(user_input_ptr_copy, New_Line_Delim);
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
		}
	}
	return (argv);
}
