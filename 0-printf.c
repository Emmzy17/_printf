#include "main.h"
#include <stdio.h>
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
	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
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
