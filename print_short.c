#include "main.h"

/**
 * print_short_decimal - prints short decimal
 * @args: the arguement
 * Return: total character printed
 */
int print_short_decimal(va_list args)
{
	short int num = va_arg(args, int);
	char num_str[10];
	int index = 0;
	int i = 0;

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
 * print_short_unsigned - print unsigned integer
 * @args: the argument
 * Return: total chracter printed
 */
int print_short_unsigned(va_list args)
{
	unsigned short int num = (unsigned short int)va_arg(args, int);
	char num_str[10];
	int i;
	int index = 0;
	int len = 0;


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
 * print_short_octal - prints the octal value
 * @args: the argument
 * Return: total character printed
 */
int print_short_octal(va_list args)
{
	unsigned short int num = (unsigned short int)va_arg(args, int);
	char num_str[10];
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
 * print_short_hex_lower - print short hexadecimal in lowercase
 * @args: the argument
 * Return: total character
 */
int print_short_hex_lower(va_list args)
{
	unsigned short int num = (unsigned short int)va_arg(args, int);
	char num_str[10];
	int index = 0;
	int len = 0;
	int i;
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

	for (i = index - 1; 1 >= 0; i--)
	{
		_putchar(num_str[i]);
		len++;
	}

	return (len);
}

/**
 * print_short_hex_upper - print short hexdecimal
 * @args: the arguments
 * Return: total char printed
 */
int print_short_hex_upper(va_list args)
{
	unsigned short int num = (unsigned short int)va_arg(args, int);
	char hex_digits[] = "0123456789ABCDEF";
	char buffer[5];
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
