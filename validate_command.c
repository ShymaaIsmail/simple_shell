#include "main.h"

/**
 * check_not_path_executable_pwd - check_not_path_executable_pwd
 * @executable_name: executable_name
 * Return: null or executable_name
*/
char *check_not_path_executable_pwd(char *executable_name)
{
	if (executable_name != NULL && str_len(executable_name) > 0
	&& executable_name[0] != '.' && executable_name[0] != '/'
	&& access(executable_name, F_OK) != -1)
	{
		return (NULL);
	}
	else
	{
		return (executable_name);
	}
}
/**
 * get_environment_variable - gets the variable environment's variale
 * @command: the command that will search about its environment value
 * Return: path value
 */
char *get_environment_variable(char *command)
{
	int environ_index = 0, iterator, size_command;
	char *tempelate;

	for (; environ[environ_index] != NULL; ++environ_index)
	{
		tempelate = environ[environ_index];
		size_command = str_len(command);

		for (iterator = 0; iterator < size_command; iterator++)
		{
			if (tempelate[iterator] != command[iterator])
				break;
		}
		if (iterator == size_command && tempelate[iterator] == '=')
		{
			return (tempelate + iterator + 1);
		}
	}
	return (NULL);
}

/**
 * validate_command - to find the location of the command
 * @command: command to get its location
 * Return: string (location of the command)
 */
char *validate_command(char *command)
{
	char *path, *copy, *token, *file_path;
	size_t command_size, token_size;
	struct stat tempelate;

	command_size = str_len(command);
	path = get_environment_variable("PATH");
	if (path != NULL)
	{
	copy = strdup(path);
	token = strtok(copy, COLON);
	while (token)
	{
		token_size = str_len(token);
		file_path = malloc(token_size + command_size + 2);
		if (file_path == NULL)
		{
			break;
		}
		str_cpy(file_path, token), strcat(file_path, "/");
		strcat(file_path, command), strcat(file_path, "\0");
		if (stat(file_path, &tempelate) == 0)
		{
			free(copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			token = strtok(NULL, COLON);
		}
	}
	}
	if (check_not_path_executable_pwd(command) != NULL
			&& stat(command, &tempelate) == 0)
	{
		free(copy);
		return (command);
	}
	free(copy);
	return (NULL);
}
