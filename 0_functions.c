#include "main.h"
/**
*print_unknown - Print an unknown specifier
*@c: Specifier character
*Return: Number of characters printed
**/
int print_unknown(char c)
{
	_putchar('%'); /* Print the '%' character */
	_putchar(c); /* Print the unknown specifier character */
	return (2); /* Return the number of characters printed (2) */
}

/**
*print_string - Print a string
*@args: va_list argument containing the string to be printed
*Return: Number of characters printed
**/
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (s == NULL)
	{
		s = "(null)";
	}

	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count);
}

/**
*print_percent - Print a percent character
*@args: va_list argument (not used)
*Return: Number of characters printed (always 1)
**/
int print_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}

/**
*print_int - Print a signed integer
*@args: va_list argument containing the integer to be printed
*Return: Number of characters printed
**/
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;

	if (n < 0)
	{
		write(1, "-", 1), count++;
		n = -n;
	}

	count += print_unsign(n, 10, "0123456789");
	return (count);
}

/**
*print_unsign - print a signed integer
*@num: va_list argument containing the integer to be printed
*@base: base
*@digits: digits
*Return: Number of characters printed
**/
int print_unsign(unsigned int num, int base, const char *digits)
{
	int count = 0;
	char buffer[32];

	int i = 0;
	int j;

	j = i - 1;
	do {
		buffer[i++] = digits[num % base];
		num /= base;
	} while (num > 0);
	for (; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}
	return (count);
}
