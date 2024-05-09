SRCS = pipex.c utils.c libft.h libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

${NAME} : ${SRCS}
	${CC} -o ${NAME} ${SRCS}

all : ${NAME}

clean :
	rm -f ${NAME}

fclean :
	rm -f ${NAME}

re : fclean all

