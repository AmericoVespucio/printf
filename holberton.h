#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>

/**
 * struct print_arguments - Struct print arguments
 *
 * @c: the character
 * @f: The function associated
 */
typedef struct print_arguments
{
	char *c;
	int (*f)();
} pa;
int _putchar(char c);
int _printf(const char *format, ...);
int _strlen(char *s);
int print_char(va_list list);
int print_string(va_list list);
int print_int(va_list list);
int print_percent(void);
#endif
