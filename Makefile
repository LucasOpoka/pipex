SRCS = pipex.c utils.c libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

${NAME} : ${SRCS}
	${CC} ${CFLAGS} ${SRCS} libft.h
	mv a.out pipex

all : ${NAME}

clean :
	rm -f ${NAME}

fclean :
	rm -f ${NAME}

re : fclean all

