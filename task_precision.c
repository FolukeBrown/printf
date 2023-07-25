#include "main.h"

/**
 * handle_precision - Checks precision validity
 * @conv: Conversion specifier  
 * Return: 1 if valid, 0 if invalid
*/
int handle_precision(char conv)
{
        int i;
        char *valid_conversions = "scdiouxXeEfFgGaA%";

        for (i = 0; valid_conversions[i]; i++)
        {
                if (conv == valid_conversions[i])
                        return (1);
        }

        return (0);
}

/**
 * get_precision - Parses precision from format string
 * @format: Format string
 * @i: Pointer to current index
 * @list: Argument list
 * Return: Precision value or -1 if invalid
*/
int get_precision(const char *format, int *i, va_list list)
{
        int curr_i, precision = -1;

        if (format[*i + 1] != '.')
                return (precision);

        precision = 0;

        for (curr_i = *i + 2; format[curr_i]; curr_i++)
        {
                if (is_digit(format[curr_i]))
                        precision = (precision * 10) + (format[curr_i] - '0'); 
                else if (format[curr_i] == '*')
                        precision = va_arg(list, int);
                else if (!handle_precision(format[curr_i]))
                        return (-1);
        }

       *i = curr_i - 1;
       return (precision);
}
