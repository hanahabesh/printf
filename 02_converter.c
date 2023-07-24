#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @types: arguments
 * @buffer: handle print
 * @flags: tive flags
 * @width:  width
 * @precision: Precision spec
 * @size: spcifier
 * Return: Nreturn char
 */
int print_unsigned(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int a = va_arg(types, unsigned long int);

	a = convert_size_unsgnd(a, size);
	if (a == 0)
		buffer[n--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (a > 0)
	{
		buffer[i--] = (a % 10) + '0';
		a /= 10;
	}
	n++;
	return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}


/**
 * print_octal - octal notation
 * @types:arguments
 * @buffer: array int
 * @flags:  active flags
 * @width: get width
 * @precision: cification
 * @size: size
 * Return: return char
 */
int print_octal(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


/**
 * print_hexadecimal - Prints a notation
 * @types: arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x',
width, precision, size));
}


/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X',
width, precision, size));
}


/**
 * print_hexa - Prints lower or upper
 * @types:  arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	       int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
