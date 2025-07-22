/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:28:35 by totake            #+#    #+#             */
/*   Updated: 2025/07/22 17:45:52 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_fractol *f, double cx, double cy)
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
		y = 2.0 * x * y + cy;
		x = xtemp;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_fractol *f)
{
	int		x;
	int		y;
	double	cx;
	double	cy;
	int		iter;

	f->max_iter = (int)(100 + 20 * log2(f->zoom));
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cx = 1.5 * (x - WIDTH / 2) / (WIDTH * 0.5 * f->zoom) + f->offset_x;
			cy = (y - HEIGHT / 2) / (HEIGHT * 0.5 * f->zoom) + f->offset_y;
			iter = mandelbrot(f, cx, cy);
			my_mlx_pixel_put(f, x, y, get_color(iter, f));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
