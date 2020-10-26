#include "holberton.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - print
 * @format: string
 * Return: Always n.
 */
int _printf(const char *format, ...)
{
	pa type[] = {
		{"c", print_char}, {"s", print_string},
		{"i", print_int}, {"d", print_int},
		{"%", print_percent}, {NULL, NULL}
	};
	int i, j, c, numchar = 0;
	va_list list;

	va_start(list, format);
	if (format == NULL)
	{
		/*write(1, "(null)", 7);*/
		return (-1);
	}
	for (i = 0; format[i] != '\0'; i++)
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			c = format[i];
			write(1, &c, 1);
			i++;
			numchar++;
		}
		if (format[i] != '\0')
			i++;
		else
			break;
		for (j = 0; j < 6; j++)
		{
			if (type[j].c[0] == format[i])
			{
				numchar += type[j].f(list);
				break;
			}
		}
	}
	va_end(list);
	return (numchar);
}
