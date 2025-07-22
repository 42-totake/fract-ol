/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:15:01 by totake            #+#    #+#             */
/*   Updated: 2025/07/22 15:47:29 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (s && *s)
	{
		while (s[i])
			i++;
		write(1, s, i);
	}
}

void	print_usage(void)
{
	ft_putstr("\nUsage:\n");
	ft_putstr("  ./fractol mandelbrot\n");
	ft_putstr("  ./fractol julia <real> <imaginary>\n");
	ft_putstr("  ./fractol burning_ship\n");
	ft_putstr("\nExamples:\n");
	ft_putstr("  ./fractol julia -0.33 0.67\n");
	ft_putstr("  ./fractol julia -0.7 0.27015\n");
	ft_putstr("\nControls:\n");
	ft_putstr("  ESC: Exit\n");
	ft_putstr("  Arrow keys: Move\n");
	ft_putstr("  Mouse wheel: Zoom\n");
	ft_putstr("  C: Shift colors\n");
	ft_putstr("  R: Reset view\n");
}

void	free_window(t_fractol *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
}

void	handle_errors(const char *msg)
{
	int i;

	i = 0;
	write(2, "Error: ", 7);
	while (msg && msg[i])
		write(2, &msg[i++], 1);
	write(2, "\n", 1);
	print_usage();
	exit(1);
}