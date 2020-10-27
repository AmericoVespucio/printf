#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * _printf - print formatted function recreation.
 * @format: receiving string
 * Return: count, wich is a counter of all the values of the string.
 */
int _printf(const char *format, ...)
{
	pa type[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_int},
		{"%", print_percent},
		{"u", print_uint},
		{NULL, NULL}
	};
	int count = 0;
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);
	count = code_block(format, list, type);
	va_end(list);
	return (count);
}
/**
 * code_block - Printf function working code block
 * @format: receiving string
 * @list: va_list list, taking arguments
 * @type: calling the struct type
 *
 * Return: numchar, wich is a counter of the inputted string arguments.
 */
int code_block(const char *format, va_list list, pa *type)
{
	int i = 0, j, c = 0, numchar = 0, found = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if  (format[i + 1] == '\0')
			{
				return (-1);
			}
			for (j = 0; type[j].c != NULL; j++)
			{
				if (type[j].c[0] == format[i + 1])
				{
					numchar += type[j].f(list);
					found = 1;
					break;
				}
			}
		}
		if (found == 1)
		{
			if (format[i + 1] == '\0' || format[i + 2] == '\0')
			{
				break;
			}
			else
				i += 2;
		}
		else
		{
			c = format[i];
			write(1, &c, 1);
			i++;
			numchar++;
		}
		found = 0;
	}
	return (numchar);
}
