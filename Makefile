# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 17:39:51 by lopoka            #+#    #+#              #
#    Updated: 2024/05/24 17:10:23 by lopoka           ###   ########.fr        #
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

all : mandatory

mandatory : .mandatory

.mandatory : ${OFILES}
	${MAKE} -C ${LIBFT}
	${CC} -o ${NAME} ${CFLAGS} ${OFILES} ${LIBFT}/libft.a
	@touch .mandatory
	@rm -f .bonus

bonus : .bonus

.bonus : ${B_OFILES}
	${MAKE} -C ${LIBFT}
	${CC} -o ${NAME} ${CFLAGS} ${B_OFILES} ${LIBFT}/libft.a
	@touch .bonus
	@rm -f .mandatory

%.o: %.c
	${CC} ${CFLAGS} ${DEPSFLAGS} -c -o $@ $<

-include ${DEPS}

clean :
	rm -f ${OFILES} ${DEPS} ${B_OFILES} ${B_DEPS}
	${MAKE} -C ${LIBFT} clean
	@rm -f .bonus .mandatory	

fclean :
	rm -f ${NAME} ${OFILES} ${DEPS} ${B_OFILES} ${B_DEPS}
	${MAKE} -C ${LIBFT} fclean
	@rm -f .bonus .mandatory

re : fclean all

redeps:
	touch ${DEPS}
	make
	${MAKE} -C ${LIBFT} redeps

.PHONY: all clean fclean re redeps libft
