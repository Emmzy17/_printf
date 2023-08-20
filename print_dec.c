#include "main.h"

/**
 * print_decimal - prints decimal values to the standard output
 * @args: a va_list type variable cotaining the integer
 * Return: number of bytes printed (success)
*/
int print_decimal(va_list args)
{
	int i = 0;
	int exp = 1;
	int num = va_arg(args, int);
	int ncopy;

	if (num < 0)
	{
		_putchar('-');
		num *= -1;
		i++;
	}
	ncopy = num;

	while (ncopy / 10)
	{
		exp *= 10;
		ncopy /= 10;
	}

	while (exp)
	{
		ncopy = num / exp;
		_putchar('0' + ncopy);
		num -= (ncopy * exp);
		exp /= 10;
		i++;
	}
	return (i);
}

/**
 * print_integer - prints decimal values to the standard output
 * @args: a va_list type variable cotaining the integer
 * Return: number of bytes printed (success)
*/
int print_integer(va_list args)
{
	int i = 0;
	int exp = 1;
	int num = va_arg(args, int);
	int ncopy;

	if (num < 0)
	{
		_putchar('-');
		num *= -1;
		i++;
	}
	ncopy = num;

	while (ncopy / 10)
	{
		exp *= 10;
		ncopy /= 10;
	}

	while (exp)
	{
		ncopy = num / exp;
		_putchar('0' + ncopy);
		num -= (ncopy * exp);
		exp /= 10;
		i++;
	}
	return (i);
}
