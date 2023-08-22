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
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent},
	{'d', print_integer},
	{'i', print_integer},
	{'b', print_binary},
	{'p', print_pointer},
	{0, NULL},
	};

	lenght_modifier_t len_mods[] = {
		{'l', 'd', print_long_integer},
		{'l', 'i', print_long_integer},
		{'h', 'd', print_short_integer},
		{'h', 'i', print_short_integer},
		{0, 0, NULL},
	};

	for (i = 0; formats[i].specifier; i++)
	{
		if (formats[i].specifier == *s)
		{
			return (formats[i].f);
		}
	}
	for (j = 0; len_mods[j].modifier == *s || len_modd[j].specifier == *s[1]; j++)
	{
		if (len_mods[j].specifier == *s[0] && len_mods[j].specifier == *s[1])
		{
			return (len_mods[j].f);
		}
	}
	return (NULL);
}

