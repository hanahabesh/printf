#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int j, ci;
	int flags = 0;
	const char CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (ci = *i + 1; format[ci] != '\0'; ci++)
	{
		for (j = 0; CH[j] != '\0'; j++)
			if (format[ci] == CH[j])
			{
				flags |= ARR[j];
				break;
			}
		if (CH[j] == 0)
			break;
	}
	*i = ci - 1;
	return (flags);
}
