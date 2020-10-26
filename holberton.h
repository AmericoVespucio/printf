#ifndef HOLBERTON_H
#define HOLBERTON_H
/**
 * struct tipo - Struct tipo
 *
 * @c: the character
 * @f: The function associated
 */
typedef struct print_arguments
{
	char *c;
	void (*f)();
} pa;
int _printf(const char *format, ...);
#endif
