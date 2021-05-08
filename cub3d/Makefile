NAME = Cub3D

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = libft/libft.a
#LIB = libft/libft.a

MLXFLAGS = -framework OpenGL -framework AppKit mlx/libmlx.dylib
#MLXFLAGS = -lX11 -lXext

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
	cp mlx/libmlx.dylib ./
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
