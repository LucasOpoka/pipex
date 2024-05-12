SRCS = sources/pipex.c sources/utils.c sources/libft.a sources/split2.c sources/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

${NAME} : ${SRCS}
	${CC} ${CFLAGS} ${SRCS} sources/libft.h sources/ft_printf.h
	mv a.out pipex

all : ${NAME}

clean :
	rm -f ${NAME}

fclean :
	rm -f ${NAME}

re : fclean all

