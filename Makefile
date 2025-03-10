CC = cc
CFLAGS = -Wall -Werror -Wextra -Iminilibx-linux # -Iminilibx-linux tells the compiler where to look for the mlx.h file

SRC_DIR = src/
SRCS = main.c init.c cleanup.c input_reading.c utils.c color.c color2.c calculate_fractal.c \
		zoom.c panel.c

SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJS = $(SRC:.c=.o)

NAME = fractol

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux

# Default target
all: $(NAME)

# Build the fractol program
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_DIR)/libmlx.a -lXext -lX11 -lbsd -lm -o $(NAME)


# Rule to compile .o files from .c files
$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

# Clean object files
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean all build artifacts
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

# Debug target to print variables
debug:
	@echo "OBJS = $(OBJS)"
	@echo "LIBFT = $(LIBFT)"

.PHONY: all clean fclean re debug
