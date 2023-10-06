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
