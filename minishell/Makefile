NAME = minishell

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = libft/libft.a

HEADER = include/minishell.h

SRCS = src/main.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo
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
