/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:25:13 by totake            #+#    #+#             */
/*   Updated: 2025/07/23 15:27:17 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_fractol *f, double mouse_re, double mouse_im, double factor)
{
	f->offset_x = mouse_re + (f->offset_x - mouse_re) / factor;
	f->offset_y = mouse_im + (f->offset_y - mouse_im) / factor;
	f->zoom *= factor;
	f->max_iter += 1;
}

void	zoom_out(t_fractol *f, double mouse_re, double mouse_im, double factor)
{
	f->offset_x = mouse_re + (f->offset_x - mouse_re) * factor;
	f->offset_y = mouse_im + (f->offset_y - mouse_im) * factor;
	f->zoom /= factor;
	if (f->max_iter > 16)
		f->max_iter -= 1;
}

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	double	zoom_factor;
	double	mouse_re;
	double	mouse_im;

	zoom_factor = 1.1;
	if (button == ZOOM_IN || button == ZOOM_OUT)
	{
		mouse_re = 1.5 * (x - WIDTH / 2) / (WIDTH * 0.5 * f->zoom)
			+ f->offset_x;
		mouse_im = (y - HEIGHT / 2) / (HEIGHT * 0.5 * f->zoom) + f->offset_y;
		if (button == ZOOM_IN)
			zoom_in(f, mouse_re, mouse_im, zoom_factor);
		else
			zoom_out(f, mouse_re, mouse_im, zoom_factor);
		draw_fractol(f);
	}
	return (0);
}
