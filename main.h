#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

extern char buffer[1024];
extern int buf_index;

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int _printf(const char *format, ...);
int (*get_print_function(char s))(va_list);
int _putchar(char c);
int print_specifier(const char *format, va_list args);
int print_integer(va_list args);
int print_unsigned_integer(va_list args);
int print_octal(va_list list);
int print_hex(va_list list);
int print_HEX(va_list list);
char *convert(unsigned long int num, int base, int lowercase);
int is_non_alpha_numeric(char c);
int print_String(va_list val);
int print_binary(va_list args);
int print_pointer(va_list args);
int print_hex(unsigned long int n);
int _strcmp(char *s1, char *s2);

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
	char *specifier;
	int (*f)(va_list);
} format_t;


#endif
