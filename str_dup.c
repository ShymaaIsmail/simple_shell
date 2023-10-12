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

	strcpy(str_new, str);
	*str_new = '\0';
	return (str_new_start);
	}
	}
}
