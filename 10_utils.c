#include "main.h"

/**
 * is_printable - is  a char is printable
 * @a: Char.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char a)
{
	if (a >= 32 && a < 127)
		return (1);
	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal
 * @buf: Array of chars.
 * @i: start appending.
 * @ascii: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii, char buf[], int i)
{
	char map[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;
	buf[i++] = '\\';
	buf[i++] = 'x';
	buf[i++] = map[ascii / 16];
	buf[i] = map[ascii % 16];
	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @a: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}

/**
 * convert_size_unsgnd -  a number to the sp
 * @num: Number
 * @size: Number indicating the casted
 *
 * Return: Casted value
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
