/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:43:52 by totake            #+#    #+#             */
/*   Updated: 2025/07/23 15:43:58 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_double(const char *s)
{
	int	has_dot;

	has_dot = 0;
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}
