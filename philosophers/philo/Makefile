NAME = philo

FLAGS = -Wall -Wextra -Werror

CC = gcc

HEADER = src/philo.h

SRCS = src/main.c \
src/utils.c \
src/philo.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
	@echo "Make done"
	@echo "------------------------"
	@echo "Usage : \n./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o ${NAME}

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
