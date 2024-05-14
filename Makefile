# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 17:39:51 by lopoka            #+#    #+#              #
#    Updated: 2024/05/14 20:53:14 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = sources/pipex.c sources/utils.c

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./sources/libft

DEPSFLAGS += -MMD -MP

OFILES = ${SRCS:.c=.o}

DEPS = ${SRCS:.c=.d}

LIBFT = ./sources/libft

all : ${NAME}

libft :
	${MAKE} -C ${LIBFT}

${NAME} : ${OFILES} libft
	${CC} -o ${NAME} ${CFLAGS} ${OFILES} ${LIBFT}/libft.a

%.o: %.c
	${CC} ${CFLAGS} ${DEPSFLAGS} -c -o $@ $<

-include ${DEPS}

clean :
	rm -f ${OFILES} ${DEPS}
	${MAKE} -C ${LIBFT} clean

fclean :
	rm -f ${NAME} ${OFILES} ${DEPS}
	${MAKE} -C ${LIBFT} fclean

re : fclean all

redeps:
	touch ${DEPS}
	make
	${MAKE} -C ${LIBFT} redeps

.PHONY: all clean fclean re redeps libft
