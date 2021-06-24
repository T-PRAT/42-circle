NAME = philo

FLAGS = -Wall -Wextra -Werror -pthread

CC = gcc

HEADER = src/philo.h

SRCS = src/main.c \
src/utils.c \
src/philo.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o ${NAME}

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
