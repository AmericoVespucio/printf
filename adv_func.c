#include "holberton.h"

/**
 *
 */
int print_bin(va_list list)
{
	unsigned int i, n = va_arg(list, unsigned int);

	for (i = 0; n > 0; i++)
	{
		bin = n % 2;
		_putchar(bin + '0');
		n = n / 2;
	}
	return (i);
}

/**
 * print_uint - main function
 * @list: The argument pointer.
 *
 * Description: This function prints a unsigned int.
 *
 * Return: 0.
 */
int print_uint(va_list list)
{

	unsigned int num, div, i = 0;

	num = va_arg(list, int);

	if (num == 0)
	{
		_putchar('0');
		i = 1;
	}
	if (num > 0)
	{
		for (div = 1; (num / div) > 9; div *= 10)
			;
		while (div != 0)
		{
			_putchar((num / div) + '0');
			num %= div;
			div /= 10;
			i++;
		}
	}
	return (i);

}
