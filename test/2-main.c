#include "holberton.h"
#include <stdio.h>
int main(void)
{
	char c = 'C';
	char *str = NULL;

	/* "Print the character c" */
	_printf("Print the character %c", c);

	/* "Print the string Hello" */
	_printf("Print the string %s", str);

	/* "Print a % sign" */
	_printf("Print a %% sign");

	/* "Print the number 5 since number 5 is great" */
	_printf("Print the number %i since number %d is great", NULL, 9);

	return (0);
}
