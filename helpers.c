#include "main.h"

/**
 * number_len - get the number of space for a value
 * @number: the number
 * @base: the base number
 * Return: the number of space
 */
int number_len(int number, int base)
{
	int len;

	while (number)
	{
		len++;
		number /= base;
	}
	return (len);
}
