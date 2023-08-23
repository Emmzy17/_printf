#include "main.h"

/**
 * print_long_decimal - prints long decimals
 * @args: arguments
 * Return: total printed characterd
 */
int print_long_decimal(va_list args)
{
	long int num = va_arg(args, int);
	char num_str[20];
	int index = 0;
	int i;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num)
	{
		num_str[index++] = (num % 10) + '0';
		num /= 10;
	}
	num_str[index] = '\0';
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(num_str[i]);
	}

	return (index);
}

/**
 * print_long_unsigned - prints long unsigned integer
 * @args: the argument
 * Return: the total printed character
 */
int print_long_unsigned(va_list args)
{
	unsigned long int num  = va_arg(args, unsigned long int);
	char num_str[25];
	int index = 0;
	int len = 0;
	int i;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		num_str[index++] = (num % 10) + '0';
		num /= 10;
	}
	num_str[index] = '\0';

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(num_str[i]);
		len++;
	}

	return (len);

}

/**
 * print_long_octal - print long octal
 * @args: the argument
 * Return: total character printed
 */
int print_long_octal(va_list args)
{
	unsigned long int num = va_arg(args, unsigned long int);
	char num_str[25];
	int index = 0;
	int len = 0;
	int i;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		num_str[index++] = (num % 8) + '0';
		num /= 8;
	}
	num_str[index] = '\0';

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(num_str[i]);
		len++;
	}

	return (len);
}

/**
 * print_long_hex_lower - prints lone hex in lowercase
 * @args: the argument
 * Return: total character printed
 */
int print_long_hex_lower(va_list args)
{
	unsigned long int num = va_arg(args, unsigned long int);
	char num_str[25];
	int index = 0;
	int len = 0;
	int  i;
	char hex_chars[] = "0123456789abcdef";

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{

		num_str[index++] = hex_chars[num % 16];
		num /= 16;
	}
	num_str[index] = '\0';

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(num_str[i]);
		len++;
	}

	return (len);
}

/**
 * print_long_hex_upper - print long hex in uppercase
 * @args: the argument
 * Return: total character printed
 */
int print_long_hex_upper(va_list args)
{
	unsigned long int num = (unsigned long int)va_arg(args, int);
	char hex_digits[] = "0123456789ABCDEF";
	char buffer[17];
	int i = 0;
	int count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num)
	{
		buffer[i++] = hex_digits[num % 16];
		num /= 16;
	}

	while (i)
	{
		_putchar(buffer[--i]);
		count++;
	}

	return (count);
}
