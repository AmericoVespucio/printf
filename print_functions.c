#include "holberton.h"
/**
 * print_main - It prints to stdout.
 * @c: Char to print.
 * Return: It returns to stdout.
 */
int print_main(int c)
{
	return (write(1, &c, 1));
}
/**
 * print_char - It prints to stdout.
 * @ch: List VF to print.
 * Return: It returns to stdout.
 */
int print_char(va_list ch)
{
	return (print_main(va_arg(ch, int)));
}
/**
 * print_percent - It prints to stdout.
 * Return: It returns to stdout.
 */
int print_percent(void)
{
	print_main('%');
	return (1);
}

/**
 * print_str - It prints to stdout.
 * @str: List VF to print.
 * Return: It returns to stdout.
 */
int print_str(va_list str)
{
	int i;
	char *txt;

	txt = va_arg(str, char*);
	i = 0;

	if (!txt)
		txt = "(null)";

	while (*(txt + i))
	{
		print_main(*(txt + i));
		i++;
	}

	return (i);
}

/**
 * print_rev - It prints to stdout.
 * @str: List VF to print.
 * Return: It returns to stdout.
 */
int print_rev(va_list str)
{
	int i;
	char *txt, *tmp;

	txt = va_arg(str, char*);
	i = 0;

	if (!txt)
		txt = "(null)";

	tmp = calloc(sizeof(txt) + 1, 1);

	while (*(txt + i))
		*(tmp + i) = *(txt + i), i++;

	_reverse(tmp);

	*(tmp + i) = '\0';

	i = 0;

	while (*(tmp + i))
	{
		print_main(*(tmp + i));
		i++;
	}

	return (i);
}
