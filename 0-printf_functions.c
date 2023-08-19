#include "main.h"
#include <stdio.h>
/**
 * print_char - prints a char
 * @args: arguements
 * Return: 1
 */
int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	putchar(c);
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
	int count;
	int i;

	if (!str)
		return (NULL);
	str = va_arg(args, const char *);
	for (i = 0; str[i]; i++)
	{
		putchar(str[i]);
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
	putchar('%');
	return (1);
}
