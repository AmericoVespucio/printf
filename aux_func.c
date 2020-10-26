#include <unistd.h>
#include "holberton.h"
#include <stdarg.h>

/**
 * _strlen - Entry point
 * @s: int
 * Return: void (Success)
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
 * @list: list
 *
 * Return: Nothing
 */
int print_char(va_list list)
{
	char c;

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
	if (str == NULL)
		str = "(null)";
	if (str[0] == '\0')
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
	int n = va_arg(list, int);
	int num, last = n % 10, digit, exp = 1;
	int  i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');

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
