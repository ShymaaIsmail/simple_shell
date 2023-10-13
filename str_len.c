#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 *str_len  - measure str length
 *@s: pointer to  string
 *Return:string length
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
