#include "main.h"

/** 
 * handle_precision - Checks if precision is valid for a conversion
 * @conv: The conversion specifier character
 *
 * Return: 1 if precision is valid, 0 if invalid
*/
int handle_precision(char conv)
{
        int i;
        char *valid_conversions = "scdiouxXeEfFgGaA%";

        for (i = 0; valid_conversions[i]; i++) 
        {
                if (conv == valid_conversions[i])
                {
                        return (1);
                }
        }

        return (0);
}

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
        int curr_i = *i + 1;
        int precision = -1;

        if (format[curr_i] != '.')
        {
                return (precision);
        }

        precision = 0;

        for (curr_i += 1; format[curr_i]; curr_i++)
        {
                if (is_digit(format[curr_i]))
                {
                        precision = precision * 10 + (format[curr_i] - '0');
                }
                else if (format[curr_i] == '*') 
                {
                        curr_i++;
                        precision = va_arg(list, int);
                        break;
                }
                else if (!handle_precision(format[curr_i]))
                {
                        precision = -1;
                        break;
                }
        }

        *i = curr_i - 1;
	
        return (precision);  
}
