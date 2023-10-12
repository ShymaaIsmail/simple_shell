#include "main.h"

/**
* check_mode - determine whether the shell
* usage mode interactive or not
* @ac: arguments count
* Return: 1 or 0
*/
int check_mode(int ac)
{
	int mode = INTERACTIVE_INPUT;

	if (!isatty(STDIN_FILENO) && ac == 1)
	{
		mode = PIPE_INPUT;
	}
	else if (!isatty(STDIN_FILENO) && ac > 1)
	{
		mode = FILE_INPUT;
	}
	return (mode);
}
#include "main.h"

/**
* display_user_prompt - display_user_prompt
* @argv: array of pointers with args
* @exit_code: exit_code
* Return: void
*/
void display_user_prompt(char **argv, int *exit_code)
{
	ssize_t chars_count;
	char *user_input_ptr = NULL;
	size_t n = 0;
	char *program_name = argv[0];
	char ***commands;

	while (1)
	{
		write(STDOUT_FILENO, Prompt_Title, 2);
		chars_count = getline(&user_input_ptr, &n, stdin);
		if (chars_count == EOF)
		{
			execute_eof();
		}
		signal(SIGINT, execute_signal_interupt);
		commands = extract_tokens(user_input_ptr);
		if (commands != NULL)
		{
			execute_command(program_name, commands, exit_code);
		}
	}
	free_all(2, &user_input_ptr, &argv);
}
#include "main.h"

/**
 * get_line_number - get_line_number
 * @line_index: line_index
 * Return: stringified line number
*/
int get_line_number(int line_index)
{
	return (line_index + 1);
}
/**
* process_command - execute_command
* @argv: 2 d array for user input
* Return: int
*/
int process_command(char **argv)
{
	int exit_code;
	char *command;
	pid_t child_pid;
	int status;

	command = validate_command(argv[0]);
	if (command)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			exit(EXIT_ERROR);
		}
		else if (child_pid == 0)
		{
			exit_code = execve(command, argv, environ);
			if (exit_code == -1)
			{
				perror("execve");
				exit(exit_code);
			}
			}
		else
		{
			waitpid(child_pid, &status, 0);
			if (WIFEXITED(status))
			{
			exit_code = WEXITSTATUS(status);
			if (exit_code != 0)
			{
				exit_code =  2;
			}
			}
			else
			{
				exit_code = 3;
			}
		}
	}
	return (exit_code);
}

/**
* execute_command - execute_command
* @program_name: program name
* @argv: 2d array for user input
* @exit_code: exit code
*/
void execute_command(char *program_name, char ***argv, int *exit_code)
{
		int line_index;

		char *command;

		if (argv != NULL && program_name != NULL)
		{
			for (line_index = 0; argv[line_index] != NULL; line_index++)
			{

				command = argv[line_index][0];
				if (str_cmp(command, EXIT) == 0)
				{
					*exit_code = execute_exit(argv[line_index], program_name,
												get_line_number(line_index), *exit_code);
				}
				else if (str_cmp(command, ENV) == 0)
				{
					execute_env(exit_code);
				}
				else
				{
					*exit_code = process_command(argv[line_index]);
				}
			}
		}
}
#include "main.h"

/**
 *  execute_env - prints local environment variables
 * @exit_code: exit_code
 * Return: void
*/
void execute_env(int *exit_code)
{
	char **current_local_env = environ;

	while (*current_local_env != NULL)
	{
		write(STDOUT_FILENO, *current_local_env, str_len(*current_local_env));
		write(STDOUT_FILENO, "\n", 1);
		current_local_env++;
	}
	*exit_code = EXIT_SUCCESS;
}
#include "main.h"
/**
* execute_eof - execute_eof
*/
void execute_eof(void)
{
	printf("Exiting shell....\n");
	exit(EXIT_SUCCESS);
}
#include "main.h"

/**
 * execute_exit - function that apply the exit of the shell
 * @command: the command that will be excuted
 * @program_name: program_name
 * @line_number: line_number
 * @previous_error_code: previous_error_code
 * Return: (void) no return value
*/
int execute_exit(char **command, char *program_name, int line_number,
				int previous_error_code)
{
	int first_arg = 1;
	int command_index = 0;
	int r;

	if (command[first_arg])
	{
		r = stoi(command[first_arg]);
		if (r == -1)
		{
			r = 2;
			print_shell_error((enum ERROR_CODE)ILLEGAL_PARAMETER, 4, program_name,
								line_number, command[command_index], command[first_arg]);
			return (r);
		}
		free_matrix(command);
		exit(r);
	}
	free_matrix(command);
	if (previous_error_code == 0 || (isatty(STDIN_FILENO)
			&& previous_error_code > 0))
	{
		exit(EXIT_SUCCESS);
	}
	{
		return (previous_error_code);
	}
}
#include "main.h"

/**
* execute_signal_interupt - execute_signal_interupt
* @signal: signal
*/
void execute_signal_interupt(int signal)
{
	exit(signal * 0);
}
#include "main.h"


/**
 * remove_leading_traling_space - remove_leading_traling_space
 * @str: str
 * Return: clean string
*/
void remove_leading_traling_space(char *str)
{
	int i, j;
	int length = 0;

	if (str != NULL)
	{
		length = str_len(str);
		i = 0;
		while (str[i] == ' ')
		{
			i++;
		}
		if (i > 0)
		{
			for (j = 0; j < length - i + 1; j++)
			{
				str[j] = str[j + i];
			}
		}
		length = str_len(str);
		i = length - 1;
		while (str[i] == ' ')
		{
			str[i] = '\0';
			i--;
		}
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
	char *temp_input = strdup(input);

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
	free(temp_input);
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
	char *copy_input = strdup(input);

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
	free(copy_input);
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
	char *copy_input = strdup(input);

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
		}
		free(row_copy);
	}

	if (copy_input != NULL)
		free(copy_input);
	return (substring);
}

/**
* extract_tokens - extract_tokens
* @user_input_ptr: pointer to content entered by a user
* Return: 2 dimensional array of all commands lines
* and arguments written by the user
*/
char ***extract_tokens(char *user_input_ptr)
{
	char *user_input_ptr_copy = strdup(user_input_ptr);
	char  ***argv = NULL;
	size_t rows_count = 0, columns_count = 0, row_index, column_index = 0, i = 0;

	if (user_input_ptr_copy != NULL)
	{
		rows_count = get_rows_count(user_input_ptr_copy);
		if (rows_count > 0)
		{
		argv = (char ***)malloc((rows_count + 1) * sizeof(char **));
		if (argv != NULL)
		{
			for (row_index = 0; row_index < rows_count ; row_index++)
			{
				columns_count = get_columns_count_by_row_index
									(user_input_ptr_copy, row_index);
				argv[row_index] = malloc(((columns_count + 1) * sizeof(char *)));
				if (argv[row_index] != NULL)
				{
					for (column_index = 0; column_index < columns_count; column_index++)
					{
						argv[row_index][column_index] = get_substring_by_indexes
														(user_input_ptr_copy, row_index, column_index);
					}
					argv[row_index][columns_count] = NULL;
				}
				else
				{
					for (i = 0; i < row_index; i++)
					{
						free(argv[i]);
					}
					free(argv);
					argv = NULL;
					break;
				}
			}
			if (argv != NULL)
			{
				argv[rows_count] = NULL;
			}
		}
	}
	free(user_input_ptr_copy);
	}
	return (argv);
}
#include "main.h"
/**
* free_all - free all passed pointers of any void* type
* @ptr_num: number of passed pointers
* Return: void
*/
void free_all(int ptr_num, ...)
{
	if (ptr_num > 0)
	{
		int ptr_index = 0;

		va_list ptr;
		void ***ptr_to_release;

		va_start(ptr, ptr_num);
		while (ptr_index < ptr_num)
		{
		ptr_to_release = va_arg(ptr, void ***);

		if (*ptr_to_release != NULL)
		{
		free(*ptr_to_release);
		*ptr_to_release = NULL;
		}
		ptr_index++;
		}
		va_end(ptr);
	}
}
#include "main.h"

/**
* main - main
* @ac: d
* @argv: f
* Return: int
*/
int main(int ac, char **argv)
{
	int shell_mode = check_mode(ac);
	int exit_code = EXIT_SUCCESS;

	if (shell_mode == INTERACTIVE_INPUT)
	{
		display_user_prompt(argv, &exit_code);
	}
	else if (shell_mode == FILE_INPUT)
	{
		process_non_interactive_file(argv, &exit_code);
	}
	else if (shell_mode == PIPE_INPUT)
	{
		process_non_interactive_pipe(argv[0], &exit_code);
	}
	return (exit_code);
}
#include "main.h"

/**
 * free_matrix - frees the 2d array
 * @mat: the matrix that will be freed
 * Return: (Void) no value
 */
void free_matrix(char **mat)
{
	int idx = 0;

	if (!mat || mat == NULL)
		return;
	while (mat[idx])
	{
		free(mat[idx]);
		idx++;
	}
	free(mat);
}
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
#include "main.h"

/**
 *  process_non_interactive_file - process_non_interactive_file
 * @argv: array of args
 * @exit_code: exit_code
*/
void process_non_interactive_file(char **argv, int *exit_code)
{
	printf(" file name is %s %d \n", argv[1], *exit_code);
}
#include "main.h"

/**
* process_non_interactive_pipe - process_non_interactive_pipe
* @program_name: program_name
* @exit_code: exit_code
*/
void process_non_interactive_pipe(char *program_name, int *exit_code)
{
	char *input;
	char buffer[(BUFFER_SIZE * 2) + 1];
	ssize_t input_data_size;
	char ***commands;

	input_data_size = read(STDIN_FILENO, buffer, BUFFER_SIZE * 2);
	if (input_data_size > 0)
	{
		input = malloc(input_data_size + 1);
		if (input != NULL)
		{
			buffer[input_data_size] = '\0';
			str_cpy(input, buffer);
			commands = extract_tokens(input);
			if (commands != NULL && program_name != NULL)
			{
				execute_command(program_name, commands, exit_code);
			}
		}
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 *str_cat - concatenates two strings
 *@s1: string 1
 *@s2: string 2
 *Return: pointer to the concatenated string
 */
char *str_cat(char *s1, char *s2)
{
	char *str_new;
	char *str_new_start;

	s1 = (s1 == NULL) ? "" : s1;
	s2 = (s2 == NULL) ? "" : s2;

	str_new = (char *)malloc(sizeof(char) * (str_len(s1) + str_len(s2) + 1));
	str_new_start = str_new;

	if (str_new == NULL)
	{
		return (NULL);
	}
	else
	{
	while (*s1 !=  '\0')
	{
		*str_new = *s1;
		str_new++;
		s1++;
	}
	while (*s2 !=  '\0')
	{
		*str_new = *s2;
		str_new++;
		s2++;
	}
	*str_new = '\0';
	return (str_new_start);
	}
}
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 *str_cmp - string compare
 *@s1: pointer to first string
 *@s2: pointer to second  string
 *Return: int to indicate which string is bigger thatn the other
 */

int str_cmp(char *s1, char *s2)
{
	int i;
	int retValue = 0;

	for (i = 0; (s1[i] != '\0' && s2[i] != '\0'); i++)
	{
		retValue = s1[i] - s2[i];
		if (retValue == 0)
			continue;
		else
			break;
	}

	return (retValue);
}
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 *str_cpy - string copy and return pointer
 *@dest: pointer to the destination
 *@src: pointer to the source
 *Return: return a point of string to the destination
 */

char *str_cpy(char *dest, char *src)
{
	int i;
	int length = strlen(src);

	for (i = 0; i < length; i++)
	{
		if (src[i] != '\0')
		{
			dest[i] = src[i];
		}
	}
	dest[length] = '\0';
	return (dest);
}
#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 *str_dup  - returns a pointer to a newly allocated
 *space in memory, which contains a copy of the string given as a parameter.
 *@str: string
 *Return: pointer to the newly copied string
 */
char *str_dup(char *str)
{
	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
	size_t length = str_len(str);
	char *str_new = (char *)malloc(sizeof(char) * (length + 1));

	if (str_new == NULL)
	{
		return (NULL);
	}
	else
	{
	char *str_new_start = str_new;

	memcpy(str_new, str, length);
	*str_new = '\0';
	return (str_new_start);
	}
	}
}
#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * stoi - converts the string to an integer
 * @s: string that will be converted
 * Return: integer converted
 */
int stoi(char *s)
{
	int val = 0;
	int ret = 0;
	int i = 0;

	if (s[0] == '-')
	{
		return (-1);
	}
	else
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if ((s[i] >= '0') && (s[i] <= '9'))
			{
				val *= 10;
				val += (s[i] - '0');
				ret = val;
			}
			else
			{
				ret = -1;
				break;
			}
		}
	}
	return (ret);
}
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * str_int_cat - str_int_cat
 * @number: number
 * @str: str
 * Return: string
*/
char *str_int_cat(int number, char *str)
{
	int temp = number;
	int digit_count = 0, result_length = 0, index = 0;
	int str_length = str_len(str);
	char *result, *number_str;

	while (temp != 0)
	{
		digit_count++;
		temp /= 10;
	}
	result_length = digit_count + str_length + 1;
	result = malloc(result_length * sizeof(char));
	if (result == NULL)
	{
		return (NULL);
	}

	number_str = malloc((digit_count + 1) * sizeof(char));
	if (number_str == NULL)
	{
		free(result);
		return (NULL);
	}
	index = digit_count - 1;
	while (number != 0)
	{
		number_str[index] = '0' + (number % 10);
		number /= 10;
		index--;
	}
	number_str[digit_count] = '\0';
	str_cpy(result, number_str);
	str_cat(result, str);
	free(number_str);
	return (result);
}
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 *str_len  - measure str length
 *@s: pointer to  string
 *Return:string length
 */

int str_len(char *s)
{
	int length = 0;
	char *remaning_text = s + 1;

	if (*s != 0)
	{
		length++;
		length +=  str_len(remaning_text);
	}
	return (length);
}
#include "main.h"

/**
 *  validate_command - validate_command
 *  @command: command
 *  Return: corrected command
*/
char *validate_command(char *command)
{
	/**
	 * check that the command is valid path and return the full
	 * command path
	*/
	return (command);
}
