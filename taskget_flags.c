#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int j, self_i;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (self_i = *i + 1; format[self_i] != '\0'; self_i++)
	{
		for (j = 0; FLAGS_CHAR[j] != '\0'; j++)
			if (format[self_i] == FLAGS_CHAR[j])
			{
				flags |= FLAGS_ARRAY[j];
				break;
			}

		if (FLAGS_CHAR[j] == 0)
			break;
	}

	*i = self_i - 1;

	return (flags);
}
