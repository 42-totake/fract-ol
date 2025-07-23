/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:29:19 by totake            #+#    #+#             */
/*   Updated: 2025/07/23 15:29:21 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shift_colors(t_fractol *f)
{
	f->color_shift = (f->color_shift + 3) % 32;
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
		f->max_iter = MAX_ITER;
	}
	draw_fractol(f);
	return (0);
}

int	handle_close(t_fractol *f)
{
	free_window(f);
	exit(0);
	return (0);
}
