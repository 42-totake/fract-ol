/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:24:34 by totake            #+#    #+#             */
/*   Updated: 2025/07/22 19:34:47 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractol(t_fractol *f)
{
	if (f->fractol_type == MANDELBROT)
		draw_mandelbrot(f);
	else if (f->fractol_type == JULIA)
		draw_julia(f);
	else if (f->fractol_type == BURNINGSHIP)
		draw_burning_ship(f);
}

int	perse_args(int argc, char **argv)
{
	int	fractol_type;

	fractol_type = 0;
	if (argc != 2 && argc != 4)
		handle_errors("Invalid number of arguments.");
	else if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
		fractol_type = MANDELBROT;
	else if (argc == 2 && ft_strcmp(argv[1], "burning_ship") == 0)
		fractol_type = BURNINGSHIP;
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0 && is_double(argv[2])
		&& is_double(argv[3]))
		fractol_type = JULIA;
	else
		handle_errors("Invalid fractal name rule.");
	return (fractol_type);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	f.fractol_type = perse_args(argc, argv);
	if (f.fractol_type == JULIA)
	{
		f.julia_c.re = ft_atod(argv[2]);
		f.julia_c.im = ft_atod(argv[3]);
	}
	init_fractol(&f);
	mlx_key_hook(f.win, handle_key, &f);
	mlx_mouse_hook(f.win, handle_mouse, &f);
	mlx_hook(f.win, 17, 0, handle_close, &f);
	draw_fractol(&f);
	mlx_loop(f.mlx);
	return (0);
}
