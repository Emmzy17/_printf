#include "main.h"
int buf_index = 0;
char buffer[1024];

/**
 * _printf - prints different data types just like printf
 * @format: the type of data type
 * Return: number of character printed
 */
int _printf(const char *format, ...)
{
	int count = 0;

	va_list(args);
	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	count = print_specifier(format, args);
	if (buf_index > 0)
	{
		write(1, buffer, buf_index);
		buf_index = 0;
	}
	va_end(args);
	return (count);
}

/**
 * print_specifier - print associated format
 * @format: the formatted string
 * @args: the argument received
 * Return: number of character printed
 */
int print_specifier(const char *format, va_list args)
{
	int i, count = 0;
	int (*func)(va_list);

	if (!format)
	{
		return (-1);
	}
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				_putchar(format[i]);
				count++;
				continue;
			}
			func = get_print_function(format[i + 1]);
			if (func)
			{
				count += func(args);
				i++;
			}
			else
			{
				_putchar(format[i]);
				count++;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	return (count);
}
