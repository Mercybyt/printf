#ifndef HOLBERTON_H
#define HOLBERTON_H

/**
 *struct Cspecs - struction definition
 *@cs: definition for character
 *@f: pointer to f
 */
typedef struct Cspecs
{
	char cs;
	void (*f)();
}
cs_t;

void _putchar_c(char c);
void _putchar(va_list a);
void print_str(va_list a);
int _printf(const char *format, ...);

#endif
