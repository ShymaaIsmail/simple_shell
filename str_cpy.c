#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 *str_cpy - string copy and return pointer
 *@dest: pointer to the destination
 *@src: pointer to the source
 *Return: return a point of string to the destination
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
