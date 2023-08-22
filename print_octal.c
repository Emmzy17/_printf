#include "main.h"

/**
 * print_octal - Prints the numeric representation of a number in octal base
 * @list: List of all the arguments passed to the program
 * Return: Number of symbols printed to stdout
 */

int print_octal(va_list list)
{
	unsigned int num;
	int len;
	char *result;
	char *str;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = char_len(num, 8);

	result = malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		result[len] = (num % 8) + 48;
		num = num / 8;

	}
	result[len] = '\0';
	str = rev_string(result);
	if (str == NULL)
		return (-1);

	wrte_char(str);
	free(result);
	free(str);
	return (len);
}
