#include "string.h"
#include "main.h"

const SHELL_ERORR shell_errors[] = {
	{NOT_FOUND_COMMAND, "%s command not found  %s\n"},
	{ILLEGAL_PARAMETER, "%s: %d: %s: Illegal number: %s\n"}
};

/**
 * process_shell_error - process_shell_error
 * @error_code: error_code
 * @ptr: ptr
 * Return: nothing
*/
void process_shell_error(enum ERROR_CODE error_code, va_list ptr)
{
	char *original_message = malloc(150);
	char *error_message = malloc(150);
	int char_index = 0, length = 0;
	char *ptr_to_replace = NULL;
	int int_value;

	if (original_message != NULL && error_message != NULL)
	{
		mem_set(error_message, 0, 150);
		str_cpy(original_message, shell_errors[error_code].message);

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
					str_int_cat(int_value, ptr_to_replace);
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
		free(error_message);
		free(original_message);
	}
}


/**
* print_shell_error - dynamic print for error msg based on enum code
* @error_code: enum for shell_error codes
* @ptr_num: number of passed pointers
* Return: void
*/
void print_shell_error(enum ERROR_CODE error_code, int ptr_num, ...)
{
	va_list ptr;

	va_start(ptr, ptr_num);
	if ((int)error_code >= 0 && (int)error_code < MAX_CODE)
	{
		if (ptr_num > 0)
		{
			process_shell_error(error_code, ptr);
			return;
		}
		else
		{
			write(STDERR_FILENO, shell_errors[error_code].message,
				  str_len(shell_errors[error_code].message));
		}
	}
	va_end(ptr);
}
