#include "string.h"
#include "main.h"

const SHELL_ERORR shell_errors[] = {
	{NOT_FOUND_COMMAND, "%s command not found  %s\n"},
	{ILLEGAL_PARAMETER, "%s: %d: %s: Illegal number: %s\n"}
};

/**
* print_shell_error - dynamic print for error msg based on enum code
* @error_code: enum for shell_error codes
* @ptr_num: number of passed pointers
* Return: void
*/
void print_shell_error(enum ERROR_CODE error_code, int ptr_num, ...)
{
	if ((int) error_code >= 0 && (int) error_code < MAX_CODE)
	{
		char *original_message = malloc(100);
		char *error_message =  malloc(100);
		int char_index = 0, length = 0;
		va_list ptr;
		char *ptr_to_replace;
		int int_value;

		if (ptr_num > 0)
		{
		if (original_message != NULL && error_message != NULL)
		{
			str_cpy(original_message, shell_errors[error_code].message);
			va_start(ptr, ptr_num);
			while (original_message[char_index] != '\0')
			{
				if (original_message[char_index] == '%')
				{
					if (original_message[char_index + 1] == 's')
					{
						ptr_to_replace = va_arg(ptr, char *);
					}
					else if (original_message[char_index + 1] == 'd')
					{
						int_value = va_arg(ptr, int);
						ptr_to_replace = str_int_cat(int_value, "");
					}
					error_message = strcat(error_message, ptr_to_replace);
					char_index += 2;
					continue;
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
			free_all(2, &original_message, &error_message);
		}
		}
		else
			write(STDERR_FILENO, shell_errors[error_code].message,
			str_len(shell_errors[error_code].message));
		}
}
