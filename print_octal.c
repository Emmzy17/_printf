#include "main.h"

/**
 * print_octal - Prints the octal representation of a number
 * @args: arguments passed
 * Return: total number of character printed
 */

int print_octal(va_list args)
{
	unsigned int num;
	int len, lcopy, i;
	char *result;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = number_len(num, 8);
	lcopy = len;

	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (-1);
	while (number)
	{
		result[len - 1] = (number % 8) + 48;
		number /= 8;
		len--;
	}
	result[lcopy] = '\0';
	for (i = 0; result[i] != '\0'; i++)
	{
		_putchar(result[i]);
	}
	free(result);
	return (len);
}
