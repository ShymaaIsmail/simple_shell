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
			columns_token = strtok(rows_token, Space_Delim);
                        while (columns_token != NULL)
			{
                                      columns_count++;
                                      columns_token = strtok(NULL, " ");
                        }
			rows_token = strtok(NULL, New_Line_Delim);
		}
		
		argv = (char **)malloc((rows_count + 1) * sizeof(char *));
                
		if (argv != NULL)
		{
			for (i = 0; i < rows_count ; i++)
			{
               			argv[i] = (char *)malloc(columns_count * sizeof(char));
			}
			rows_token = strtok(user_input_ptr, New_Line_Delim);
			i = 0;
    while (rowToken != NULL) {
        colToken = strtok(rowToken, " ");
        j = 0;
        while (colToken != NULL) {
            array[i][j] = atoi(colToken);
            j++;
            colToken = strtok(NULL, " ");
        }
        i++;
        rowToken = strtok(NULL, "\n");
    }
			argv[i] = NULL;
		}
	}
	return (argv);
}
