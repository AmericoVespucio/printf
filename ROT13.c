#include "holberton.h"

/**
* rot13 - Prints the string in ROT13.
* @str: String to translate.
*
* Return: Number of characters printed.
*/

int rot13(va_list str)
{
	int i = 0, r = 0, c = 0;
	char *s;
	char *abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *nop = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(str, char *);

	if (!s)
		s = "(null)";

	while (*(s + i))
	{
		while (*(abc + r))
		{
			if (*(s + i) == *(abc + r))
			{
				c += print_main(*(nop + r));
				break;
			}
			r++;
		}
		if (*(s + i) != *(abc + r))
			c += print_main(*(s + i));
		i++, r = 0;
	}

	return (c);
}
