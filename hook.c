/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:27:21 by totake            #+#    #+#             */
/*   Updated: 2025/07/22 17:27:25 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shift_colors(t_fractol *f)
{
	f->color_shift = (f->color_shift + 3) % 24;
}

int	handle_key(int keycode, t_fractol *f)
{
	if (keycode == ESC)
	{
		free_window(f);
		exit(0);
	}
	else if (keycode == LEFT)
		f->offset_x -= 1.0 / f->zoom;
	else if (keycode == RIGHT)
		f->offset_x += 1.0 / f->zoom;
	else if (keycode == UP)
		f->offset_y -= 1.0 / f->zoom;
	else if (keycode == DOWN)
		f->offset_y += 1.0 / f->zoom;
	else if (keycode == KEY_C)
		shift_colors(f);
	else if (keycode == KEY_R)
	{
		f->zoom = 1.0;
		f->offset_x = -0.5;
		f->offset_y = 0.0;
		f->color_shift = 0;
	}
	draw_fractol(f);
	return (0);
}

// int	mouse_hook(int keycode, int x, int y, t_fractol *f)
// {
// 	(void)x;
// 	(void)y;
// 	if (keycode == MOUSE_UP)
// 	{
// 		p->zoom *= 1.1;
// 		p->max_n += 5;
// 	}
// 	else if (keycode == MOUSE_DOWN)
// 	{
// 		p->zoom *= 0.9;
// 		p->max_n -= 5;
// 		if (p->max_n <= 100)
// 			p->max_n = 100;
// 	}
// 	draw_fractol(p);
// 	return (0);
// }

// int	handle_mouse(int button, int x, int y, t_fractol *f)
// {
// }

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	double	zoom_factor;
	double	mouse_re;
	double	mouse_im;

	zoom_factor = 1.5;
	if (button == ZOOM_IN || button == ZOOM_OUT)
	{
		mouse_re = 1.5 * (x - WIDTH / 2) / (WIDTH * 0.5 * f->zoom)
			+ f->offset_x;
		mouse_im = (y - HEIGHT / 2) / (HEIGHT * 0.5 * f->zoom) + f->offset_y;
		if (button == ZOOM_IN)
		{
			f->offset_x = mouse_re + (f->offset_x - mouse_re) / zoom_factor;
			f->offset_y = mouse_im + (f->offset_y - mouse_im) / zoom_factor;
			f->zoom *= zoom_factor;
		}
		else if (button == ZOOM_OUT)
		{
			f->offset_x = mouse_re + (f->offset_x - mouse_re) * zoom_factor;
			f->offset_y = mouse_im + (f->offset_y - mouse_im) * zoom_factor;
			f->zoom /= zoom_factor;
		}
		draw_fractol(f);
	}
	return (0);
}

int	handle_close(t_fractol *f)
{
	free_window(f);
	exit(0);
	return (0);
}