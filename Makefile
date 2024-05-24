# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 17:39:51 by lopoka            #+#    #+#              #
#    Updated: 2024/05/24 15:33:56 by lopoka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = sources/pipex.c \
	   sources/ft_first_child.c \
	   sources/ft_middle_child.c \
	   sources/ft_last_child.c \
	   sources/ft_child_processes_utils.c \
	   sources/ft_exe.c \
	   sources/ft_find_pth.c \

B_SRCS = sources/pipex_bonus.c \
		 sources/ft_first_child.c \
		 sources/ft_here_doc_bonus.c \
		 sources/ft_middle_child.c \
		 sources/ft_last_child.c \
		 sources/ft_child_processes_utils.c \
		 sources/ft_exe.c \
		 sources/ft_find_pth.c \


CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./sources/libft

DEPSFLAGS += -MMD -MP

OFILES = ${SRCS:.c=.o}

B_OFILES = ${B_SRCS:.c=.o}

DEPS = ${SRCS:.c=.d}

B_DEPS = ${B_SRCS:.c=.d}

LIBFT = ./sources/libft

all : ${NAME}

libft :
	${MAKE} -C ${LIBFT}

${LIBFT}/libft.a: libft

${NAME} : ${OFILES} ${LIBFT}/libft.a
	${CC} -o ${NAME} ${CFLAGS} ${OFILES} ${LIBFT}/libft.a

bonus : .bonus

.bonus : ${B_OFILES} ${LIBFT}/libft.a
	${CC} -o ${NAME} ${CFLAGS} ${B_OFILES} ${LIBFT}/libft.a
	@touch .bonus

%.o: %.c
	${CC} ${CFLAGS} ${DEPSFLAGS} -c -o $@ $<

-include ${DEPS}

clean :
	rm -f ${OFILES} ${DEPS} ${B_OFILES} ${B_DEPS}
	${MAKE} -C ${LIBFT} clean
	@rm -f .bonus	

fclean :
	rm -f ${NAME} ${OFILES} ${DEPS} ${B_OFILES} ${B_DEPS}
	${MAKE} -C ${LIBFT} fclean
	@rm -f .bonus

re : fclean all

redeps:
	touch ${DEPS}
	make
	${MAKE} -C ${LIBFT} redeps

.PHONY: all clean fclean re redeps libft
