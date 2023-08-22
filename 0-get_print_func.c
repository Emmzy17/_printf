#include "main.h"

/**
 * get_print_function - selects the function for a specifier
 * @s: specifier
 * Return: a pointer to function
 */
int (*get_print_function(char *s))(va_list)
{
	int i, j;

	format_t formats[] = {
	{"c", print_char},
	{"s", print_string},
	{"%", print_percent},
	{"d", print_integer},
	{"i", print_integer},
	{"b", print_binary},
	{"p", print_pointer},
	{"u", print_unsigned_integer},
	{"ld", print_long_decimal},
	{"li" print_long_integer},
	{"lu", print_long_unsigned},
	{"lo", print_long_octal},
	{"lx", print_long_hex},
	{"lX", print_long_HEX},
	{"hd", print_short_decimal},
	{"hi", print_short_integer},
	{"hu", print_short_unsigned},
	{"ho", print_short_octal},
	{"hx", print_short_hex},
	{"hX", print_short_HEX},
	{NULL, NULL},

	};


	for (i = 0; formats[i].specifier; i++)
	{
		if (_strcmp(formats[i].specifier, s) == 0)
		{
			return (formats[i].f);
		}
	}

	return (NULL);
}

