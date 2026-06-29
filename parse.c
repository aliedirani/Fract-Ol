#include "fractol.h"

static const char	*skip_spaces(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

static double	parse_fraction(const char **str)
{
	double	value;
	double	scale;

	value = 0.0;
	scale = 0.1;
	while (ft_isdigit(**str))
	{
		value += (**str - '0') * scale;
		scale *= 0.1;
		(*str)++;
	}
	return (value);
}

static double	parse_integer(const char **str, bool *has_digit)
{
	double	value;

	value = 0.0;
	while (ft_isdigit(**str))
	{
		*has_digit = true;
		value = (value * 10.0) + (**str - '0');
		(*str)++;
	}
	return (value);
}

double	ft_atof(const char *str, bool *ok)
{
	double	value;
	double	sign;
	bool	has_digit;

	value = 0.0;
	sign = 1.0;
	has_digit = false;
	str = skip_spaces(str);
	if (*str == '+' || *str == '-')
		sign = 1.0 - 2.0 * (*str++ == '-');
	value = parse_integer(&str, &has_digit);
	if (*str == '.')
	{
		str++;
		if (ft_isdigit(*str))
			has_digit = true;
		value += parse_fraction(&str);
	}
	str = skip_spaces(str);
	*ok = (*str == '\0' && has_digit);
	return (value * sign);
}
