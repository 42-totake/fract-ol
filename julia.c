/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:37:44 by totake            #+#    #+#             */
/*   Updated: 2025/07/23 14:37:46 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fractol *f, double zx, double zy)
{
	double	tmp;
	int		i;

	i = 0;
	while (zx * zx + zy * zy <= 4.0 && i < f->max_iter)
	{
		tmp = zx * zx - zy * zy + f->julia_c.re;
		zy = 2.0 * zx * zy + f->julia_c.im;
		zx = tmp;
		i++;
	}
	return (i);
}

void	draw_julia(t_fractol *f)
{
	int		x;
	int		y;
	double	zx;
	double	zy;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			zx = 1.5 * (x - WIDTH / 2) / (WIDTH * 0.5 * f->zoom) + f->offset_x;
			zy = (y - HEIGHT / 2) / (HEIGHT * 0.5 * f->zoom) + f->offset_y;
			iter = julia(f, zx, zy);
			my_mlx_pixel_put(f, x, y, get_color(iter, f));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
