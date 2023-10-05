#include "string.h"
#include "main.h"

const SHELL_ERORR shell_errors[] = {
	{NOT_FOUND_COMMAND, "%s command not found  %s"}
};

/**
* print_shell_error - dynamic print for error msg based on enum code
* @shell_error: enum for shell_error codes
* @ptr_num: number of passed pointers
* Return: void
*/
void print_shell_error(SHELL_ERORR shell_error, int ptr_num, ...)
{
	if ((int) shell_error.code >= 0 && (int) shell_error.code < MAX_CODE)
	{
		char *original_message = malloc(500 * sizeof(char));
		char *error_message = malloc(500 * sizeof(char));
		int char_index = 0, length = 0;
		va_list ptr;
		char *ptr_to_replace;

		if (ptr_num > 0)
		{
		if (original_message != NULL && error_message != NULL)
		{
			str_cpy(original_message, shell_errors[shell_error.code].message);
			va_start(ptr, ptr_num);
			while (original_message[char_index] != '\0')
			{
				if (original_message[char_index] == '%' &&
					original_message[char_index + 1] == 's')
				{
					ptr_to_replace = va_arg(ptr, char *);
					error_message = str_cat(error_message, ptr_to_replace);
					char_index += 2;
				}
				else
				{
					length = str_len(error_message);
					error_message[length] = original_message[char_index];
					char_index++;
				}
			}
			va_end(ptr);
			write(STDERR_FILENO, error_message, str_len(error_message));
		}
		}
		else
		{
			write(STDERR_FILENO, shell_errors[shell_error.code].message,
					str_len(shell_errors[shell_error.code].message));
		}
		free_all(2, original_message, error_message);
	}
}
