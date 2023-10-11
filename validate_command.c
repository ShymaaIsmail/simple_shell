#include "main.h"

/**
 * get_environment_variable - gets the variable environment's variale
 * @command: the command that will search about its environment value
 * Return: path value
 */
char *get_environment_variable(char *command)
{
	int idx1 = 0, idx2, size_command;
	char *temp;

	for (; environ[idx1] != NULL; ++idx1)
	{
		temp = environ[idx1];
		size_command = str_len(command);

		for (idx2 = 0; idx2 < size_command; idx2++)
		{
			if (temp[idx2] != command[idx2])
				break;
		}
		if (idx2 == size_command && temp[idx2] == '=')
		{
			return (temp + idx2 + 1);
		}
	}
	return (NULL);
	/*if returned null thus it is not validate */
}


/**
 * get_path - to find the location of the command
 * @command: command to get its location
 * Return: string (location of the command)
 */

char *validate_command(char *command)
{
	char *command_path, *copied_path, *token_path, *file_path;
	size_t command_size, directory_size;
	struct stat buf;

	command_path = get_environment_variable("PATH");
	if (command_path)
	{
		copied_path = str_dup(command_path);
		command_size = str_len(command);
		token_path = strtok(copied_path, ":");

		while (token_path)
		{
			directory_size = str_len(token_path);
			file_path = malloc (command_size + directory_size + 2);
			str_cpy(file_path, copied_path);
			str_cat(file_path, token_path);
			str_cat(file_path, "/");
			str_cat(file_path, command);
			str_cat(file_path, "\0");
			
			if (stat(file_path, &buf) == 0)
			{
				free(copied_path);
				return (file_path);
			}
			else
			{
				free(file_path);
				token_path = strtok(NULL, ":");
			}
		}
		free(copied_path);
		if (stat (command, &buf) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
