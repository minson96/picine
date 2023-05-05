# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 20:03:49 by minson            #+#    #+#              #
#    Updated: 2022/10/19 19:48:42 by minson           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c

NAME	= libft.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

AR		= ar

ARFLAGS	= src

INCLUDE = ./includes/

OBJS	= ${SRCS:.c=.o}

all: ${NAME}

${NAME} : ${OBJS}
	${AR} ${ARFLAGS} $@ $^

%.o: ${SRCS}
	${CC} ${CFLAGS} -c $< -o $@ -I${INCLUDE}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
