#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 *str_cpy - copy the string into another one
 *@dest: pointer to the destination string
 *@src: pointer to the source string
 *Return: return a pointer to the destination
 */

char *str_cpy(char *dest, char *src)
{
	int i;
	int length = strlen(src);

	for (i = 0; i < length; i++)
	{
		if (src[i] != '\0')
		{
			dest[i] = src[i];
		}
	}
	dest[length] = '\0';
	return (dest);
}
