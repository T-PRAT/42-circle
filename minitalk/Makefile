S_NAME = server

C_NAME = client

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = libft/libft.a

S_HEADER = include/server.h

C_HEADER = include/client.h

S_SRCS = src/server.c

C_SRCS = src/client.c

S_OBJS = $(S_SRCS:.c=.o)

C_OBJS = $(C_SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(S_NAME) $(C_NAME)

$(S_NAME): $(S_OBJS)
	$(MAKE) -C libft
	$(CC) -o ${S_NAME} -I$(S_HEADER) $(S_OBJS) $(LIB)

$(C_NAME): $(C_OBJS)
	$(CC) -o ${C_NAME} -I$(C_HEADER) $(C_OBJS) $(LIB)

clean:
	rm -f $(C_OBJS) $(S_OBJS)
	make clean -C libft

fclean: clean
	rm -f $(C_NAME) $(S_NAME)
	make fclean -C libft

re: fclean all

.PHONY: fclean re norme all clean
