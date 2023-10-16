#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * str_int_cat - converts str to int and connacetates it into provided string
 * @number: integer
 * @str: string
 * Return: Void
*/
void str_int_cat(int number, char *str)
{
	int i = 0, start = 0, end = 0;
	char temp;

	str = str == NULL ? "" : str;
	while (number != 0)
	{
		str[i] = '0' + number % 10;
		number = number / 10;
		i++;
	}
	str[i] = '\0';

	start = 0;
	end = i - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
