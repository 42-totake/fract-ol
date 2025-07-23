/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:47:14 by totake            #+#    #+#             */
/*   Updated: 2025/07/23 16:47:27 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "float.h" //DBL_MAX,DBL_MIN,DBL_DIG
# include "mlx.h"
# include <math.h>   // pow, fabs(), log2()
# include <stdlib.h> //exit
# include <unistd.h> //write

// fractol index
# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3
// window setting
# define WIDTH 800
# define HEIGHT 600
// calc max
# define MAX_ITER 50
// key
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define KEY_C 99
# define KEY_R 114
# define ZOOM_IN 5
# define ZOOM_OUT 4

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	double			zoom;
	double			offset_x;
	double			offset_y;
	int				max_iter;
	unsigned int	color_shift;
	int				fractol_type;
	t_complex		julia_c;
	int				mouse_x;
	int				mouse_y;
}					t_fractol;

// main
void				draw_fractol(t_fractol *f);

// error.c
void				free_window(t_fractol *f);
void				handle_errors(const char *msg, t_fractol *f);

// double1.c
int					ft_isdigit(int c);
int					is_double(const char *s);
// double2.c
double				ft_atod(const char *s);

// utils.c
int					ft_strcmp(const char *s1, const char *s2);
void				my_mlx_pixel_put(t_fractol *f, int x, int y, int color);
void				init_fractol(t_fractol *f);

// hook1.c
int					handle_key(int keycode, t_fractol *f);
int					handle_mouse(int button, int x, int y, t_fractol *f);
// hook2.c
int					handle_close(t_fractol *f);

// color.c
int					get_color(int iter, t_fractol *f);

// mandelbrot.c
void				draw_mandelbrot(t_fractol *f);

// julia.c
void				draw_julia(t_fractol *f);

// burningship
void				draw_burning_ship(t_fractol *f);

#endif
