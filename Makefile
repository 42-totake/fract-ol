NAME    = fractol

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -O2 -Imlx

SRC     = main.c error.c double.c burningship.c  hook.c color.c julia.c mandelbrot.c  utils.c
OBJ     = $(SRC:.c=.o)

MLX_DIR = ../minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
