NAME = Cub3D

FLAGS = -Wall -Wextra

CC = gcc

LIB = libft/libft.a minilibx-linux/libmlx.a

#MLXFLAGS = -framework OpenGL -framework AppKit
MLXFLAGS = -lX11 -lXext mlx/libmlx.a -lm


HEADER = include/cub3d.h

SRCS = src/main.c \
src/map_parsing.c \
src/map_parsing2.c \
src/loop.c \
src/position.c \
src/raycasting.c \
src/raycasting2.c \
src/utils.c \
src/sprite.c \
src/save.c \
src/move.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C mlx
	$(CC) -I$(HEADER) $(FLAGS) $(OBJS) $(LIB) -o ${NAME} $(MLXFLAGS)

norme:
	norminette libft
	@echo
	norminette $(HEADER)
	@echo
	norminette $(SRCS)

clean:
	rm -f $(OBJS)
	make clean -C libft
	make clean -C mlx

fclean: clean
	rm -f $(NAME)
	rm -f libmlx.dylib
	make fclean -C libft

re: fclean all

.PHONY: fclean re norme all clean
