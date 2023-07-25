int get_precision(const char *format, int *i, va_list list)
{
	int precision = -1;
	int curr_i = 0;

	// Parse digits before '.' as precision
	curr_i = *i + 1;
	while (is_digit(format[curr_i]))
	{
		precision = precision * 10 + (format[curr_i] - '0');
		curr_i++;
	}

	// Check for '.' 
	if (format[curr_i] == '.')
	{
		curr_i++;
		
		// Parse digits after '.' as precision
		while (is_digit(format[curr_i]))
		{
			precision = precision * 10 + (format[curr_i] - '0');
			curr_i++;
		}
	}

	// Update format index
	*i = curr_i - 1;

	return (precision);
}