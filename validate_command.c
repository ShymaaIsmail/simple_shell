#include "main.h"

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
	
	if (stat(command, &temp) == 0)
		return command;
	/* printf("after\n"); */
	command_size = strlen(command);
	path = getenv("PATH");
	copy = strdup(path);
	token = strtok(copy, colon);

	/* printf("the token: %s\n", token); */
	/*printf("the copy: %s\n", copy); */
	/*printf("the path: %s\n", path); */

	while(token)
	{
		token_size = strlen(token);
		file_path = malloc(token_size + command_size + 2);

		if (file_path == NULL)
		{
			free(copy);
			perror("Memory allocated error");
		       	exit(1);
		}
		strcpy(file_path, token);
		strcat(file_path, "/");
		strcat(file_path, command);
		strcat(file_path, "\0");
		if (stat(file_path, &temp) == 0)
		{
			/*printf("valid: %s\n",path), */
			free(copy);
			return (file_path);
		}
		else
		{
			/*printf("nonvalid");*/
			free(file_path);
			token = strtok (NULL, colon);
		}
	}
	free(copy);
	return (NULL);
}
