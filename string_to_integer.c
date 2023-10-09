#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * stoi - converts the string to an integer
 * @str: string that will be converted
 * Return: integer converted
 */
int stoi(char *str)
{
	int value = 0;
	int s = 1;

	if (*str == '-')
	{
		s *= -1;
		str++;
	}
	while (*str != '\0')
	{
		if ((*str >= '0') && (*str <= '9'))
		{
			value *= 10;
			value += (*str - '0');
		}
		else
		{
			break;
		}
		++str;
	}
	return (value * s);
}
