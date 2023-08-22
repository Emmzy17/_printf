#include "main.h"

/**
 * print_unsigned_integer - prints a number in args
 * @args: list of argument
 * Return: total number of args printed
 */

int print_unsigned_integer(va_list args)
{
	int n;
	int exp;
	int len;
	unsigned int num;

	n  = va_arg(args, int);
	exp = 1;
	len = 0;

	if (n < 0)
		return (-1);
	num = n;

	while (num / exp > 9)
		exp *= 10;

	while (exp != 0)
	{
		len += _putchar('0' + num / exp);
		num %= exp;
		exp /= 10;
	}

	return (len);
}
