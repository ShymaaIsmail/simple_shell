#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * stoi - converts the string to an integer to handles the arguments of command
 * @s: string that will be converted
 * Return: converted integer
 */
int stoi(char *s)
{
	int val = 0;
	int ret = 0;
	int i = 0;

	if (s[0] == '-')
	{
		return (-1);
	}
	else
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if ((s[i] >= '0') && (s[i] <= '9'))
			{
				val *= 10;
				val += (s[i] - '0');
				ret = val;
			}
			else
			{
				ret = -1;
				break;
			}
		}
	}
	return (ret);
}
