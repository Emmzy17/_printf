#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int _printf(const char *format, ...);
int (*get_print_function(char s))(va_list);
int dec_handler(va_list value);

/**
 * struct format - the format handler structure
 * @specifier: The specified format
 * @f: The associated format handler
 *
 * Description: a structure that stores a format specifier
 * and its associated handler
*/
typedef struct format
{
	char specifier;
	int (*f)(va_list);
} format_t;

#endif
