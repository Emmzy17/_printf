#include "main.h"

/**
 * _putchar - prints a character to the standard output
 * @c: the output character
 * Return: the number of byted written (success) -1 (failure)
*/
static char buffer[1024];
static int buf_index = 0;
int _putchar(char c)
{
	buffer[buf_index] = c;
	buf_index++;

	if (buf_index == 1024)
	{
		write(1, buffer, 1024);
		buf_index = 0;
	}

	return (1);
}
