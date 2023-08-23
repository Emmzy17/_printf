#include "main.h"

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
	unsigned int mask = 1 << (sizeof(num) * 8 - 1);
	int count = 0, started = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (mask)
	{
		if (num & mask)
		{
			_putchar('1');
			count++;
			started = 1;
		}
		else if (started)
		{
			_putchar('0');
			count++;
		}

		mask >>= 1;
	}

	return (count);
}

/**
 * print_pointer - prints the pointer address
 * @args: the argument
 * Return: total number
 */
int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	unsigned long int addr = (unsigned long int)ptr;
	int count = 0;

	if (ptr == NULL)
	{
		char *nil_str = "(nil)";

		while (*nil_str)
		{
			_putchar(*nil_str);
			nil_str++;
			count++;
		}
		return (count);
	}
	else
	{
		_putchar('0');
		_putchar('x');
		count += 2;
		count += print_hex(addr);
		return (count);
	}
}

/**
 * print_hex - prints hex decimal
 * @args: the argument
 * Return: total character printed
 */
int print_hex(unsigned long int n)
{
	int count = 0;

	if (n >= 16)
	{
		count += print_hex(n / 16);
	}
	if (n % 16 < 10)
	{
		_putchar((n % 16) + '0');
	}
	else
	{
		_putchar((n % 16) - 10 + 'a');
	}

	return (count + 1);
}
