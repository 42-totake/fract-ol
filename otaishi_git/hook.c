/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:49:05 by ootaketai         #+#    #+#             */
/*   Updated: 2025/07/22 13:44:00 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int keycode, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_UP)
	{
		p->zoom *= 1.1;
		p->max_n += 5;
	}
	else if (keycode == MOUSE_DOWN)
	{
		p->zoom *= 0.9;
		p->max_n -= 5;
		if (p->max_n <= 100)
			p->max_n = 100;
	}
	draw_fractol(p);
	return (0);
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(p->mlx, p->win);
		// system("leaks fractol");
		exit(EXIT_SUCCESS);
	}
	else if (keycode == LEFT_KEY)
		p->move_x += 0.1 / p->zoom;
	else if (keycode == RIGHT_KEY)
		p->move_x -= 0.1 / p->zoom;
	else if (keycode == UP_KEY)
		p->move_y += 0.1 / p->zoom;
	else if (keycode == DOWN_KEY)
		p->move_y -= 0.1 / p->zoom;
	else if (keycode == C_KEY)
		p->c++;
	julia_change(keycode, p);
	draw_fractol(p);
	return (0);
}

int	close_hook(t_fractol *f)
{
	mlx_destroy_window(p->mlx, p->win);
	// system("leaks fractol");
	exit(EXIT_SUCCESS);
	return (0);
}

void	julia_change(int keycode, t_fractol *f)
{
	if (keycode == H_KEY)
		p->cx += 0.01;
	else if (keycode == J_KEY)
		p->cy -= 0.01;
	else if (keycode == K_KEY)
		p->cy += 0.01;
	else if (keycode == L_KEY)
		p->cx -= 0.01;
}
