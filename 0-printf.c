#include "main.h"

/**
 * _printf - prints different data types just like printf
 * @format: the type of data type
 * Return: number of character printed
 */
int _printf(const char *format, ...)
{
	int count = 0, i;
	va_list args;
	int (*func)(va_list);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				putchar(format[i]);
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
				putchar(format[i]);
				count++;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}

	va_end(args);
	return (count);
}
