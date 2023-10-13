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
	int i;
	int len1 = str_len(s1);
	int len2 = str_len(s2);
	char *str_new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));

	if (str_new == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len1; i++)
	{
		str_new[i] = s1[i];
	}

	for (i = 0; i < len2; i++)
	{
		str_new[len1 + i] = s2[i];
	}
	str_new[len1 + len2] = '\0';
	return (str_new);
}
