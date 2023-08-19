#include "main.h"

/**
 * print_dec - prints decimal values to the standard output
 * @value: a va_list type variable cotaining the integer
 * Return: number of bytes printed (success)
*/
int print_dec(va_list value)
{
	int i = 0;
	int exp = 1;
	int num = va_arg(value, int);
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
