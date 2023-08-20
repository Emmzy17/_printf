#include "main.h"

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
		i += _putchar('0' + ncopy);
		num -= (ncopy * exp);
		exp /= 10;
	}
	return (i);
}
