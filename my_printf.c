#include "main.h"

/**
 * print_putchar - print the charater
 * @buf: chars to be printed
 * @buff_i: length of the print
 */
void print_putchar(char buf[], int *buff_i)
{
	if (*buff_i > 0)
		write(1, &buff[0], *buff_i);
	*buff_i = 0;
}
/**
 * _printf - print the string and char
 * @format: arguments
 * Return: return character
 */
int _printf(const char *format, ...)
{
	int i, display = 0, print1 = 0;
	int w, f, precision, size, buf1 = 0;

	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(agrs, format);
	i = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buf1++] = format[i];
			if (buf1 == BUFF_SIZE)
				print_putchar(buffer, &buf1);
			print1++;
		}
		else
		{
			print_putchar(buffer, &buf1);
			f = get_flags(format, &i);
			w = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			diplay = handle_print(format, &i, args, buffer, f, w,
precision, size);
			if (display == -1)
				return (-1);
			print1 += display;
		}
		i++;
	}
	print_putchar(buffer, &buf1);
	va_end(args);
	return (print1);
}
