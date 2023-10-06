#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	str_new = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
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
