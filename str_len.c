#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 *str_len  - measure the size of the string
 *@s: pointer to the given string
 *Return: string length (int)
 */

int str_len(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}
