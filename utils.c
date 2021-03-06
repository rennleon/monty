#include "monty.h"

/**
 * is_number - Cheks if a string is represented only by numbers
 * @str: String to be checked
 *
 * Return: 1 if str is a number, 0 otherwise
*/
int is_number(char *str)
{
	if (str == NULL)
		return (0);

	if (*str == '-' && *(str + 1) != '\0')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}

/**
 * num_to_str - Converts a number to string
 * @num: Number to be converted
 *
 * Return: Number represented as string
*/
char *num_to_str(int num)
{
	int num_rev = 0;
	int i, digits = 0;
	char *num_str = NULL;

	if (num == 0)
		digits = 1;
	else
		while (num > 0)
		{
			digits++;
			num_rev *= 10;
			num_rev += num % 10;
			num /= 10;
		}

	num_str = malloc(sizeof(char) * (digits + 1));
	if (num_str == NULL)
		err_malloc();

	for (i = 0; i < digits; i++)
	{
		num_str[i] = (num_rev % 10) + '0';
		num_rev /= 10;
	}
	num_str[i] = '\0';

	return (num_str);
}
