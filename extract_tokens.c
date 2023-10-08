#include "main.h"


/**
 * remove_leading_traling_space - remove_leading_traling_space
 * @str: str
 * Return: clean string
*/
void remove_leading_traling_space(char *str)
{
	int i, j;
	int n = str_len(str);

	i = 0;
	while (str[i] == ' ')
	{
		i++;
	}
	if (i > 0)
	{
		for (j = 0; j < n - i + 1; j++)
		{
			str[j] = str[j + i];
		}
	}
	n = strlen(str);
	i = n - 1;
	while (str[i] == ' ')
	{
		str[i] = '\0';
		i--;
	}
}
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

	remove_leading_traling_space(temp_input);
	if (temp_input != NULL && str_len(temp_input) > 0)
	{
	rows_token = strtok(temp_input, New_Line_Delim);
	while (rows_token != NULL)
	{
		rows_count++;
		rows_token = strtok(NULL, New_Line_Delim);
	}
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
 * get_substring_by_indexes - get_substring_by_indexes
 * @input: input
 * @row_index: row_index
 * @column_index: column_index
 * Return: string
*/
char *get_substring_by_indexes(char *input, size_t row_index,
								size_t column_index)
{
	size_t current_row = 0, current_column = 0;
	char *substring = NULL;
	char *row_token, *row_copy;
	char *column_token;
	char *copy_input = str_dup(input);

	row_token = strtok(copy_input, New_Line_Delim);
	while (row_token != NULL && current_row < row_index)
	{
		row_token = strtok(NULL, New_Line_Delim);
		current_row++;
	}
	if (row_token != NULL)
	{
		row_copy = strdup(row_token);
		column_token = strtok(row_copy, Space_Delim);
		current_column = 0;
		while (column_token != NULL && current_column < column_index)
		{
			column_token = strtok(NULL, Space_Delim);
			current_column++;
		}
		if (column_token != NULL)
		{
			substring = strdup(column_token);
			free(row_copy);
			free(copy_input);
			return (substring);
		}
		free(row_copy);
	}
	free(copy_input);
	return (NULL);
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
	char  ***argv = NULL;
	size_t rows_count = 0, columns_count = 0, row_index, column_index = 0;

	if (user_input_ptr_copy != NULL)
	{
		user_input_ptr_copy = str_dup(user_input_ptr);
		rows_count = get_rows_count(user_input_ptr_copy);
		if (rows_count > 0)
		{
		argv = (char ***)malloc((rows_count + 1) * sizeof(char *));
		if (argv != NULL)
		{
			for (row_index = 0; row_index < rows_count ; row_index++)
			{
				columns_count = get_columns_count_by_row_index
									(user_input_ptr_copy, row_index);
				argv[row_index] = malloc(columns_count * sizeof(char *));
				for (column_index = 0; column_index < columns_count; column_index++)
				{
					argv[row_index][column_index] = get_substring_by_indexes
													(user_input_ptr_copy, row_index, column_index);
				}
				 argv[row_index][columns_count] = NULL;
			}
			argv[rows_count] = NULL;
		}
	}
	}
	return (argv);
}
