/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:35:12 by totake            #+#    #+#             */
/*   Updated: 2025/07/23 14:35:15 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(t_fractol *f, double cx, double cy)
{
	double	x;
	double	y;
	double	xtemp;
	int		i;

	x = 0.0;
	y = 0.0;
	i = 0;
	while (x * x + y * y <= 4.0 && i < f->max_iter)
	{
		xtemp = x * x - y * y + cx;
		y = fabs(2.0 * x * y) + cy;
		x = fabs(xtemp);
		i++;
	}
	return (i);
}

void	draw_burning_ship(t_fractol *f)
{
	int		x;
	int		y;
	double	cx;
	double	cy;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cx = 1.5 * (x - WIDTH / 2) / (WIDTH * 0.5 * f->zoom) + f->offset_x;
			cy = (y - HEIGHT / 2) / (HEIGHT * 0.5 * f->zoom) + f->offset_y;
			iter = burning_ship(f, cx, cy);
			my_mlx_pixel_put(f, x, y, get_color(iter, f));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
