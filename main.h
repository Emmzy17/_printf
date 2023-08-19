#ifndef MAIN_H
#define MAIN_H

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int _printf(const char *format, ...);

typedef struct format
{
	char specifier;
	int (*f)(va_list);
} format_t;

#endif
