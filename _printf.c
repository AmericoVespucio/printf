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
	int i = 0, j, c, numchar = 0;
	va_list list;

	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			i++;
			while (j < 5)
			{
				if (type[j].c[0] == format[i])
				{
					numchar += type[j].f(list) - 1;
					type[j].f(list);
					break;
				}
				j++;
			}
			i++;
		}
		else
		{
			c = format[i];
			write(1, &c, 1);
			i++;
		}
		numchar++;
	}
	va_end(list);
	return (numchar);
}
