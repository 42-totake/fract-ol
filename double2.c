/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:12:02 by totake            #+#    #+#             */
/*   Updated: 2025/07/23 13:15:44 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	parse_sign(const char **s)
{
	double	sign;

	sign = 1.0;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1.0;
		(*s)++;
	}
	return (sign);
}

static double	handle_overflow(double sign)
{
	if (sign < 0.0)
		return (-DBL_MAX);
	else
		return (DBL_MAX);
}

static double	parse_integer_part(const char **s, double sign)
{
	double	result;
	int		digit;

	result = 0.0;
	while (**s && ft_isdigit(**s))
	{
		digit = **s - '0';
		if (result > (DBL_MAX - digit) / 10.0)
			return (handle_overflow(sign));
		result = result * 10.0 + digit;
		(*s)++;
	}
	return (result);
}

static double	parse_fraction_part(const char **s)
{
	double	fraction;
	double	divisor;
	int		digit;

	fraction = 0.0;
	divisor = 10.0;
	if (**s == '.')
	{
		(*s)++;
		while (**s && ft_isdigit(**s))
		{
			digit = **s - '0';
			fraction += digit / divisor;
			divisor *= 10.0;
			(*s)++;
		}
	}
	return (fraction);
}

double	ft_atod(const char *s)
{
	double	sign;
	double	int_part;
	double	frac_part;

	sign = parse_sign(&s);
	int_part = parse_integer_part(&s, sign);
	frac_part = parse_fraction_part(&s);
	return (sign * (int_part + frac_part));
}
