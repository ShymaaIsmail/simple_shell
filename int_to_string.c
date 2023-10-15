#include "main.h"

/**
 * int_to_string - int_to_string
 * @number: number
 * Return: string
*/
char *int_to_string(int number)
{
	int isNegative = 0;
	int length = 0;
	int temp = number;
	int index = 0;
	char *str;

	if (number < 0)
	{
		isNegative = 1;
		temp = -temp;
		length++;
	}
	do {
		length++;
		temp /= 10;
	} while (temp);

	str = malloc((length + 1) * sizeof(char));
	if (str != NULL)
	{
	index = length - 1;
	temp = number;
	if (isNegative)
	{
		str[0] = '-';
		temp = -temp;
	}

	do {
		str[index] = '0' + (temp % 10);
		temp /= 10;
		index--;
	} while (temp);
	str[length] = '\0';
	}
	return (str);
}
