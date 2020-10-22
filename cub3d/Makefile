NAME = Cub3D

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIBFT = libft/libft.a

MLXFLAGS = -lmlx -lm -lX11 -lXext -lbsd

HEADER = -I./include

SRCS = src/main.c \
src/map_parsing.c \
src/map_parsing2.c \
src/loop.c \
src/create_image.c \
src/position.c \
src/raycasting.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(HEADER) $(FLAGS) $(OBJS) $(LIBFT) -o ${NAME} $(MLXFLAGS)


norme:
	norminette libft
	@echo
	norminette $(HEADER)
	@echo
	norminette $(SRCS)

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: fclean re norme all clean
