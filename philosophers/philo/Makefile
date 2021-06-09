NAME = philo

FLAGS = -Wall -Wextra -Werror

CC = gcc

HEADER = philo.h

SRCS = main.c \
utils.c \
philo.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -I$(HEADER) $(FLAGS) $(OBJS) -o ${NAME}

norme:
	@echo
	norminette $(HEADER)
	@echo
	norminette $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean re norme all clean
