#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 *mem_set - fills memory with a constant byte
 *@s: pointer to  string passed
 *@b: character that will fill memory
 *@n: integer (count of the bytes)
 *Return: pointer to the memset
 */

char *mem_set(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
