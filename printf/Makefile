SRCS= src/ft_printf.c

BONUS= 

OBJS= ${SRCS:.c=.o}

BOBJS= ${BONUS:.c=.o}

NAME= libftprintf.a

HEAD= ft_printf.h

CFLAGS= -Wall -Wextra -Werror

CC= cc

RM= rm -f

%o : %c ${HEAD}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):${OBJS}
	ar rc ${NAME} ${OBJS}

all:${NAME}

bonus:${OBJS} ${BOBJS}
	ar rc ${NAME} ${OBJS} ${BOBJS}

clean:
	${RM} ${OBJS} ${BOBJS}

fclean:clean
	${RM} ${NAME}

re:fclean all

.PHONY:all clean fclean re
