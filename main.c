/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:38:54 by ootaketai         #+#    #+#             */
/*   Updated: 2025/07/21 22:01:15 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractol(t_p *p)
{
	if (p->fractol == MANDELBROT)
		draw_mandelbrot(p);
	else if (JULIA1 <= p->fractol && p->fractol <= JULIA3)
		draw_julia(p);
	else if (p->fractol == BURNINGSHIP)
		draw_burningship(p);
}

void	chose_fractol(t_p *p, char *av)
{
	if (!ft_strcmp("mandelbrot", av))
	{
		p->fractol = MANDELBROT;
		p->move_x = 0.5;
		p->move_y = 0.0;
	}
	else if (!ft_strcmp("burningship", av))
		p->fractol = BURNINGSHIP;
	else
		chose_julia(p, av);
	draw_fractol(p);
}

void	error_phrase(void)
{
	write(1, "Usage: ./fractol <Fractals>\n", 28);
	write(1, "Available <Fractals>:\n", 23);
	write(1, "---> mandelbrot\n", 17);
	write(1, "---> julia1\n", 13);
	write(1, "---> julia2\n", 13);
	write(1, "---> julia3\n", 13);
	write(1, "---> burningship\n", 18);
	exit(EXIT_FAILURE);
}

int	perse_args(char *av)
{
	if (!ft_strcmp(av, "mandelbrot") || !ft_strcmp(av, "julia1")
		|| !ft_strcmp(av, "julia2") || !ft_strcmp(av, "julia3")
		|| !ft_strcmp(av, "burningship"))
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	t_p	p;

	if (argc != 2 || perse_args(argv[1]))
		error_phrase();
	init(&p);
	chose_fractol(&p, argv[1]);
	mlx_hook(p.win, 2, 1L << 0, key_hook, &p);
	mlx_hook(p.win, 4, 1L << 0, mouse_hook, &p);
	mlx_hook(p.win, 17, 0, close_hook, &p);
	mlx_loop(p.mlx);
	return (0);
}
