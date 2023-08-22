#include "main.h"

/**
 * get_print_function - selects the function for a specifier
 * @s: specifier
 * Return: a pointer to function
 */
int (*get_print_function(char *s))(va_list)
{
	int i;

	format_t formats[] = {
	{"c", print_char},
	{"s", print_string},
	{"%", print_percent},
	{"d", print_integer},
	{"i", print_integer},
	{"b", print_binary},
	{"p", print_pointer},
	{"u", print_unsigned_integer},
	{"o", print_octal},
	{"x", print_hex_lower},
	{"X", print_hex_upper},
	{"R", print_rot13},
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

