#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int _printf(const char *format, ...);
int (*get_print_function(char s))(va_list);

typedef struct format
{
	char specifier;
	int (*f)(va_list);
} format_t;

#endif
