#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format
 * Return: chars
 */
int _printf(const char *format, ...)
{
	int flags, width, precision, size, buff_ind = 0;
	int i, display = 0, print1 = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	i = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			print1++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			display = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (display == -1)
				return (-1);
			print1 += display;
		} i++;
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (print1);
}

/**
 * print_buffer - the contents of the buf
 * @buffer: Array of chars
 * @buff_ind: represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
