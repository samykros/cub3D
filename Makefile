# Nombre del ejecutable
NAME = cub3d

# Compilador y flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Paths de librerías y MiniLibX
MLX_DIR = ./libs/mlx
LIBFT_DIR = ./libs/libft
MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11
LIBS = $(LIBFT_DIR)/libft.a

# Includes
INCLUDES = -I ./include -I $(MLX_DIR)

# Archivos fuente y objetos
SRCS =	src/main.c \
		src/window.c \
		src/check_map.c \
		src/init.c \
		src/utils.c \

OBJS = $(SRCS:.c=.o)

# Regla principal
all: $(NAME)

# Compilar el ejecutable
$(NAME): $(OBJS)
	@make -C $(MLX_DIR) # Compilar MiniLibX
	@make -C $(LIBFT_DIR) # Compilar libft
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

# Compilar archivos .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Limpiar archivos .o
clean:
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

# Limpiar todo (binarios y objetos)
fclean: clean
	rm -rf $(NAME)

# Volver a compilar desde cero
re: fclean all

.PHONY: all clean fclean re
