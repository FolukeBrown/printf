#include "main.h"

/**
 * get_precision - Gets the precision for printing from format string
 * @format: Formatted string containing format specifiers
 * @i: Pointer to current index in format string 
 * @list: Argument list
 * Return: Precision value, or -1 on error  
 */
int get_precision(const char *format, int *i, va_list list)
{
	int precision = -1;
	int curr_i = 0;

	// Check if format string is valid
	if (!format || format[0] == '\0')
		return -1; 

	curr_i = *i + 1;

	// Precision starts after '.'
	if (format[curr_i] != '.')
	{
		return precision; 
	}

  // Initialize precision to 0 
	precision = 0;

	// Parse characters after '.'  
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{

	// Accumulate precision digits 
		if (is_digit(format[curr_i]))
		{

			// Check for overflow  
			if (precision > (INT_MAX / 10))
			{
				return -1;
			}

			precision = (precision * 10) + (format[curr_i] - '0');

			// Get precision from arguments 
		}
	else if (format[curr_i] == '*')
	{
		curr_i++;
		precision = va_arg(list, int);
		break;

	// Invalid character, stop parsing 
	}
	else
		break;
	}

	// Update format index
	*i = curr_i - 1;

	return (precision);
}
