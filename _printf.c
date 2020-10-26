#include "holberton.h"
/**
 * _printf - It prints with different formats.
 * @fm: Format to print.
 *
 * Return: Always returns (0).
 */
int _printf(format fm, ...)
{
	va_list fmt;
	int flag, chk;
	funcs pFmt[] = {
		{"%c", print_char},
		{"%s", print_str},
		{"%%", print_percent},
		{"%d", print_integer},
		{"%i", print_integer},
		{"%b", print_in_bases},
		{"%o", print_in_bases},
		{"%u", print_in_bases},
		{"%x", print_in_bases},
		{"%X", print_in_bases},
		{"%r", print_rev},
		{"%R", rot13}
	};

	if (!fm)
		return (-1);

	flag = 0;
	va_start(fmt, fm);

	chk = checker(fm, flag, pFmt, fmt);

	va_end(fmt);
	return (chk);
}
