#include "main.h"

/**
 * _putchar - prints a character to the standard output
 * @c: the output character
 * Return: the number of byted written (success) -1 (failure)
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
