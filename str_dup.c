#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 *str_dup  - string duplication
 *@str: string
 *Return: pointer to the newly duplicated string
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
