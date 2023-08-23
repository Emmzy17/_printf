#include "main.h"

/**
 * print_char - prints a char
 * @args: arguements
 * Return: 1
 */
int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	_putchar(c);
	return (1);
}

/**
 * print_string - prints a string
 * @args: argument
 * Return: lenght of the string
 */
int print_string(va_list args)
{
	const char *str;
	int count = 0;
	int i;

	str = va_arg(args, const char *);
	if (!str)
	{
		str = "(null)";
	}
	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}
/**
 * print_reverse - print the reverse of a string
 * @args: arguement
 * Return: length of the string
 */
int print_reverse(va_list args)
{
	const char *str;
	int len;
	int count = 0;
	int i;

	str = va_arg(args, const char *);
	if (!str)
	{
		str ="(null)";
	}
	len = rev_str(str);

	for (i = 0; i < len; i++)
	{
		_putchar(str[i]);
		count++;
	}
	
	return count;
}
	
/**
 * print_percent - prints '%' specifier
 * @args: arguements
 * Return: 1
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}
/**
 * print_binary - unsigned int is converted to binary
 * @args: arguement
 * Return: Lenght of b
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int mask = 1 << (sizeof(num) * 8 - 1);
	int count = 0, started = 0;
	

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (mask)
	{
		if (num & mask )
		{
			_putchar('1');
			count++;
			started = 1;
		}
		else if(started)
		{
			_putchar('0');
			count++;
		}

		mask >>= 1;
	}

	return (count);
}
int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	unsigned long int addr = (unsigned long int)ptr;
	int count = 0;

	if (ptr == NULL)
	{
		char *nil_str = "(nil)";
		while (*nil_str)
		{
			_putchar(*nil_str);
			nil_str++;
			count++;
		}
		return count;
	}
	else
	{
		_putchar('0');
		_putchar('x');
		count += 2;
		count += print_hex(addr);
		return (count);
	}
}

int print_hex(unsigned long int n)
{
	int count = 0;
	if (n >= 16)
	{
		count += print_hex(n / 16);
	}
	if (n % 16 < 10)
	{
		_putchar((n % 16) + '0');
	}
	else
	{
		_putchar((n % 16) - 10 + 'a');
	}
	
	return (count + 1);
}
int print_long_decimal(va_list args)
{
	long int num = va_arg(args, int);
	char num_str[20];
	int index = 0;
	int i;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num)
	{
		num_str[index++] = (num % 10) + '0';
		num /= 10;
	}
	num_str[index] = '\0';
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(num_str[i]);
	}

	return (index);
}
int print_short_decimal(va_list args)
{
	short int num = va_arg(args, int);
	char num_str[10];
	int index = 0;
	int i = 0;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num)
	{
		num_str[index++] = (num % 10) + '0';
		num /=10;
	}
	num_str[index] = '\0';

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(num_str[i]);
	}

	return (index);
}
int print_long_unsigned(va_list args)
{
	unsigned long int num  = va_arg(args, unsigned long int);
	char num_str[25];
	int index = 0;
	int len = 0;
	int i;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		num_str[index++] = (num % 10) + '0';
		num /= 10;
	}
	num_str[index] = '\0';
	
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(num_str[i]);
		len++;
	}
	
	return (len);

}
int print_short_unsigned(va_list args)
{
	unsigned short int num = (unsigned short int)va_arg(args, int);
	char num_str[10];
	int i;
	int index = 0;
	int len = 0;


	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		num_str[index++] = (num % 10) + '0';
		num /= 10;
	}
	num_str[index] = '\0';

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(num_str[i]);
		len++;
	}

	return (len);
}
int print_long_octal(va_list args)
{
	unsigned long int num = va_arg(args, unsigned long int);
	char num_str[25];
	int index = 0;
	int len = 0;
	int i;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		num_str[index++] = (num % 8) + '0';
		num /= 8;
	}
	num_str[index] = '\0';

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(num_str[i]);
		len++;
	}

	return (len);
}
int print_short_octal(va_list args)
{
	unsigned short int num = (unsigned short int)va_arg(args, int);
	char num_str[10];
	int index = 0; 
	int len = 0;
	int i;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		num_str[index++] = (num % 8) + '0';
		num /= 8;
	}
	num_str[index] = '\0';

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(num_str[i]);
		len++;
	}
	
	return (len);
}
int print_long_hex_lower(va_list args)
{
	unsigned long int num = va_arg(args, unsigned long int);
	char num_str[25];
	int index = 0;
	int len = 0;
	int  i;
	char hex_chars[] = "0123456789abcdef";
	
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{

		num_str[index++] = hex_chars[num % 16];
		num /= 16;
	}
	num_str[index] = '\0';

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(num_str[i]);
		len++;
	}

	return (len);
}
int print_short_hex_lower(va_list args)
{
	unsigned short int num = (unsigned short int)va_arg(args, int);
	char num_str[10];
	int index = 0;
	int len = 0;
	int i;
	char hex_chars[] = "0123456789abcdef";

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		num_str[index++] = hex_chars[num % 16];
		num /= 16;
	}
	num_str[index] = '\0';

	for (i = index - 1; 1 >= 0; i--)
	{
		_putchar(num_str[i]);
		len++;
	}

	return (len);
}
int print_long_hex_upper(va_list args)
{
	unsigned long int num = (unsigned long int)va_arg(args, int);
	char hex_digits[] = "0123456789ABCDEF";
	char buffer[17];
	int i = 0;
	int count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num)
	{
		buffer[i++] = hex_digits[num % 16];
		num /= 16;
	}

	while (i)
	{
		_putchar(buffer[--i]);
		count++;
	}

	return (count);
}
int print_short_hex_upper(va_list args)
{	
	unsigned short int num = (unsigned short int)va_arg(args, int);
	char hex_digits[] = "0123456789ABCDEF";
	char buffer[5];
	int i = 0;
	int count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num)
	{
		buffer[i++] = hex_digits[num % 16];
		num /=16;
	}

	while (i)
	{
		_putchar(buffer[--i]);
		count++;
	}

	return (count);
}
