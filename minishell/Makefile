NAME = minishell

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIBFT = libft/libft.a

HEADER = include/

SRCS = src/main.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -I$(HEADER) $(FLAGS) $(OBJS) $(LIB) -o ${NAME}

$(LIBFT):
	make -C ./libft

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
