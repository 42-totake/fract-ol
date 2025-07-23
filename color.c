/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:29:58 by totake            #+#    #+#             */
/*   Updated: 2025/07/23 12:22:30 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, t_fractol *f)
{
	int color;

	if (iter == f->max_iter)
		return (0x00000000);
	color = (int)(0x00FFFFFF * ((double)iter / f->max_iter));
	color = color & 0x00FFFFFF;
	color = ((color >> f->color_shift) | (color << (24
					- f->color_shift))) & 0x00FFFFFF;
	return (color);
}