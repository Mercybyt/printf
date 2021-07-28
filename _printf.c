#include "holberton.h"
#include <stdarg.h>
/**
 * _printf - print format
 * @format:char * - string
 *
 * Return: int - string length
 */
int _printf(const char *format, ...)
{
	int len = 0;
	const char *string;
	va_list arg;

	va_start(arg, format);
	if (format)
	{
		string = format;
		len = get_strlen(string);
		while (*format)
		{
			if (*format == '%')
			{
				format++;
				switch (*format)
				{
				case 's':
				{
					char *ret = va_arg(arg, char*);

					while (*ret)
					{
						_putchar(*ret);
						ret++;
					}
				}
				break;
				case 'c':
				{
					_putchar((char)va_arg(arg, int));
				}
				break;
				case 'd':
				{
					int ret = va_arg(arg, int);

					print_int(ret);
				}
				break;
				case 'i':
				{
					int ret = va_arg(arg, int);

					print_int(ret);
				}
				break;
				case '%':
				{
					_putchar('%');
				}
				break;
				default:
				{
					_putchar(*format);
				}
				break;
				}
			}
			else
			{
				_putchar(*format);
			}
			format++;
		}
	}
	return (len);
}
