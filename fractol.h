/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:14:22 by totake            #+#    #+#             */
/*   Updated: 2025/07/22 20:27:59 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h> // pow, fabs(), log2()
// # include <mlx.h>    //mlx...
# include "mlx.h"
# include <stdio.h>  // printf
# include <stdlib.h> //exit EXIT_SUCCESS..
# include <unistd.h> //write

// fractol index
# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3
// window setting
# define WIDTH 800
# define HEIGHT 600
// calc max
# define MAX_ITER 16

# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define KEY_C 99
# define KEY_R 114
# define ZOOM_IN 5
# define ZOOM_OUT 4

// # define C_KEY 8
// # define LEFT_KEY 123
// # define RIGHT_KEY 124
// # define DOWN_KEY 125
// # define UP_KEY 126
// # define H_KEY 4
// # define J_KEY 38
// # define K_KEY 40
// # define L_KEY 37
// # define MOUSE_UP 4
// # define MOUSE_DOWN 5

// typedef struct s_img
// {
// 	void		*img;
// 	char		*addr;
// 	int			bits_per_pixel;
// 	int			line_length;
// 	int			endian;
// }				t_img;

// typedef struct s_p
// {
// 	void		*mlx;
// 	void		*win;
// 	double		move_x;
// 	double		move_y;
// 	double		cx;
// 	double		cy;
// 	int			n;
// 	int			max_n;
// 	double		zoom;
// 	int			fractol;
// 	int			c;
// 	t_img		img;
// }				t_p;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			max_iter;
	int			color_shift;
	int			fractol_type;
	t_complex	julia_c;
	int			mouse_x;
	int			mouse_y;
}				t_fractol;

// main
void			draw_fractol(t_fractol *f);

// error.c
void			free_window(t_fractol *f);
void			handle_errors(const char *msg);

// double.c
int				is_double(const char *s);
double			ft_atod(const char *s);

// utils.c
int				ft_strcmp(const char *s1, const char *s2);
void			my_mlx_pixel_put(t_fractol *f, int x, int y, int color);
void			init_fractol(t_fractol *f);

// hook.c
int				handle_key(int keycode, t_fractol *f);
int				handle_mouse(int button, int x, int y, t_fractol *f);
int				handle_close(t_fractol *f);

// color.c
int				get_color(int iter, t_fractol *f);

// mandelbrot.c
void			draw_mandelbrot(t_fractol *f);

// julia.c
void			draw_julia(t_fractol *f);

// burningship
void			draw_burning_ship(t_fractol *f);

#endif
