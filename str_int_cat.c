#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * str_int_cat - str_int_cat
 * @number: number
 * @str: str
 * Return: string
*/
char *str_int_cat(int number, char *str)
{
	int temp = number;
	int digit_count = 0, result_length = 0, index = 0;
	int str_length = str_len(str);
	char *result = NULL, *number_str = NULL;

	while (temp != 0)
	{
		digit_count++;
		temp /= 10;
	}
	result_length = digit_count + str_length + 1;
	result = malloc(result_length * sizeof(char));
	if (result == NULL)
	{
		return (NULL);
	}

	number_str = malloc((digit_count + 1) * sizeof(char));
	if (number_str == NULL)
	{
		free(result);
		return (NULL);
	}
	index = digit_count - 1;
	while (number != 0)
	{
		number_str[index] = '0' + (number % 10);
		number /= 10;
		index--;
	}
	number_str[digit_count] = '\0';
	str_cpy(result, number_str);
	strcat(result, str);
	free(number_str);
	return (result);
}
