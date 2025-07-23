/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:46:38 by totake            #+#    #+#             */
/*   Updated: 2025/07/23 15:46:43 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = f->addr + (y * f->line_length + x * (f->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// mlx_init:
// mlx_init function will return a void * which holds
// the location of our current [MLX instance].
//
// mlx_new_window:
// mlx_new_window function, which will return
// a pointer to the [window] we have just created.
//
// mlx_new_image:
// mlx_new_image function, which whill return
// a pointer to the buffer. we will have to buffer
// all of our pixels to a image, which we will
// then push to the window
//
// mlx_get_data_addr:
// we need to get the memory address for bytes changes.
// After creating an image, we can call `mlx_get_data_addr`,
// we pass `bits_per_pixel`, `line_length`, and `endian`
// by reference.
void	init_fractol(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		handle_errors("Failed to mlx_init()", f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		handle_errors("Failed to mlx_new_window()", f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		handle_errors("Failed to mlx_new_image", f);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length,
			&f->endian);
	f->zoom = 1.0;
	f->offset_x = -0.5;
	f->offset_y = 0.0;
	f->max_iter = MAX_ITER;
	f->color_shift = 0;
	f->mouse_x = WIDTH / 2;
	f->mouse_y = HEIGHT / 2;
}
