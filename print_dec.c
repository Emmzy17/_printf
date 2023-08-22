#include "main.h"

/**
 * print_integer - Prints an integer
 * @args: list of argument
 * Return: total number printed
 */

int print_integer(va_list args)
{
	int len;

	len = print_number(args);
	return (len);
}


/**
 * print_number - prints a number in args
 * @args: list of argument
 * Return: total number of args printed
 */

int print_number(va_list args)
{
	int n;
	int exp;
	int len;
	unsigned int num;

	n  = va_arg(args, int);
	exp = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
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
