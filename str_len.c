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
	char *remaning_text = s + 1;

	if (*s != 0)
	{
		length++;
		length +=  str_len(remaning_text);
	}
	return (length);
}
