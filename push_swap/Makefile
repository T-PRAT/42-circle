NAME = push_swap

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = libft/libft.a

HEADER = include/push_swap.h

SRCS = src/main.c \
src/parsing.c \
src/swap_and_push.c \
src/rotate.c \
src/rrotate.c \
src/sort_utils.c \
src/sort.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) -I$(HEADER) $(FLAGS) $(OBJS) $(LIB) -o ${NAME}

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
