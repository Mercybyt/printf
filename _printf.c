#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "holberton.h"

/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int char_count = 0;
	int int_buff;
	char *str;
	char chr;
	char sint_buff[10];
	va_list vaList;

	va_start(vaList, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch(*format)
			{
			case '%':
				_putchar('%');
				format++;
				char_count++;
				break;
			case 's':
				str = va_arg(vaList, char *);
				fputs(str, stdout);
				format++;
				char_count += strlen(str);
				break;
			case 'c':
				chr = va_arg(vaList, int);
				_putchar(chr);
				format++;
				char_count++;
				break;
			case 'i':
			case 'd':
				int_buff = va_arg(vaList, int);
				itoa(int_buff, sint_buff, 10);
				fputs(sint_buff, stdout);
				format++;
				char_count += strlen(sint_buff);
				break;
			case 'u':
				int_buff = va_arg(vaList, int);
				itoa(int_buff, sint_buff, 10);
				fputs(sint_buff, stdout);
				format++;
				char_count += strlen(sint_buff);
				break;
			case 'o':
				int_buff = va_arg(vaList, int);
				itoa(int_buff, sint_buff, 8);
				fputs(sint_buff, stdout);
				format++;
				char_count += strlen(sint_buff);
				break;
			case 'x':
			case 'X':
				int_buff = va_arg(vaList, int);
				itoa(int_buff, sint_buff, 16);
				fputs(sint_buff, stdout);
				format++;
				char_count += strlen(sint_buff);
				break;
			case '\0':
				break;
			default:
				_putchar(*format);
				format++;
				char_count += 2;
				break;
			}
		}
		else
			{
				_putchar(*format);
				format++;
				char_count++;
			}
	}
	va_end(vaList);
	return (char_count);
}
