# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 08:59:26 by minson            #+#    #+#              #
#    Updated: 2022/10/20 08:59:40 by minson           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = main.c change_board.c check_base.c check_map.c declare_print.c fill_num.c read_file.c read_stdin.c set_answer.c
SRCS_DIR = $(addprefix srcs/, $(SRCS))
OBJS_DIR = $(SRCS_DIR:.c=.o)
INCLUDES_DIR = includes

CC = gcc -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

%.o: %.c
		$(CC) -I $(INCLUDES_DIR) -c $< -o $@

$(NAME): $(OBJS_DIR)
		$(CC) $(OBJS_DIR) -o $(NAME)

clean:
		$(RM) srcs/*.o

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY : all clean fclean re
