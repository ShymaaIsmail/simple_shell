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
}

/**
 * validate_command - to find the location of the command
 * @command: command to get its location
 * Return: string (location of the command)
 */
char *validate_command(char *command)
{
	char *path, *copy, *token, *file_path;
	char colon[] = ":";
	size_t command_size, token_size;
	struct stat temp;

	command_size = str_len(command);
	path = get_environment_variable("PATH");
	if (path != NULL)
	{
	copy = strdup(path);
	token = strtok(copy, colon);
	while (token)
	{
		token_size = str_len(token);
		file_path = malloc(token_size + command_size + 2);
		if (file_path == NULL)
		{
			free(copy), perror("Memory allocated error"), exit(1);
		}
		str_cpy(file_path, token);
		strcat(file_path, "/");
		strcat(file_path, command);
		strcat(file_path, "\0");
		if (stat(file_path, &temp) == 0)
		{
			free(copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			token = strtok(NULL, colon);
		}
	}
	}
	if (check_not_path_executable_pwd(command) != NULL
			&& stat(command, &temp) == 0)
		return (command);
	free(copy);
	return (NULL);
}
