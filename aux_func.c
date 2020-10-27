#include <unistd.h>
#include "holberton.h"
#include <stdarg.h>

/**
 * _strlen - calculates the lenght of a string
 * @s: pointer to string
 * Return: len (lenght)
 */
int _strlen(char *s)
{
	int n, len;

	n = len = 0;
	while (*(s + n) != '\0')
	{
		n++;
		len++;
	}
	return (len);
}

/**
 * print_char - prints a char
 * @list: list of arguments
 *
 * Return: Nothing
 */
int print_char(va_list list)
{
	char c;

	if (list == 0)
		list = NULL;
	c = va_arg(list, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @list: list
 *
 * Return: Nothing
 */
int print_string(va_list list)
{
	char *tmp;
	int n;

	tmp = va_arg(list, char *);
	if (tmp == NULL)
		tmp = "(null)";
	if (tmp[0] == '\0')
		return (0);
	n = _strlen(tmp);
	write(1, tmp, n);
	return (n);
}
/**
 * print_int - Print integers when invoked
 * @list: argument entered to print
 *
 * Return: Nothing
 */
int print_int(va_list list)
{

	long int num, div, i = 0;

	num = va_arg(list, int);

	if (num == 0)
	{
		_putchar('0');
		i = 1;
	}
	else if (num < 0)
	{
		_putchar('-');
		num = -num;
		i = 1;
	}
	if (num > 0)
	{
		for (div = 1; div <= num; div *= 10)
			;
		while (div > 1)
		{
			div /= 10;
			_putchar((num / div) + '0');
			num %= div;
			i++;
		}
	}
	return (i);
}

/**
 * print_percent - prints %
 *
 * Return: 1
 */
int print_percent(void)
{
	_putchar('%');
	return (1);
}
