#include "main.h"

/**
 * print_char - prints a char
 * @args: arguements
 * Return: 1
 */
int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	_putchar(c);
	return (1);
}

/**
 * print_string - prints a string
 * @args: argument
 * Return: lenght of the string
 */
int print_string(va_list args)
{
	const char *str;
	int count = 0;
	int i;

	str = va_arg(args, const char *);
	if (!str)
	{
		str = "(null)";
	}
	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}

/**
 * print_percent - prints '%' specifier
 * @args: arguements
 * Return: 1
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}
/**
 * print_binary - unsigned int is converted to binary
 * @args: arguement
 * Return: Lenght of b
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[33];
	char *ptr = &buffer[32];
	int count = 0;

	if (num == 0)
	{
		putchar('0');
		return (1);
	}

	while (num > 0)
	{
		ptr--;
		*ptr = (num % 2) + '0';
		num /= 2;
	}

	while (*ptr)
	{
		putchar(*ptr);
		count++;
		ptr++;
	}

	return (count);
}
