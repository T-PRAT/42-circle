NAME = server

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = libft/libft.a

HEADER = include/server.h

SRCS = src/server.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) -o ${NAME} -I$(HEADER) $(OBJS) $(LIB)

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
