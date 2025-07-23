# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 15:39:04 by totake            #+#    #+#              #
#    Updated: 2025/07/23 15:39:09 by totake           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fractol
NAME_BONUS  = fractol_bonus

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O2 -Imlx

SRC         = main.c error.c double1.c double2.c burningship.c hook1.c hook2.c color.c julia.c mandelbrot.c utils.c
SRC_BONUS   = main_bonus.c error_bonus.c double1_bonus.c double2_bonus.c burningship_bonus.c \
              hook1_bonus.c hook2_bonus.c color_bonus.c julia_bonus.c mandelbrot_bonus.c utils_bonus.c

OBJ         = $(SRC:.c=.o)
OBJ_BONUS   = $(SRC_BONUS:.c=.o)

MLX_DIR     = ../minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME) $(MLX_FLAGS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_LIB) -o $(NAME_BONUS) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
