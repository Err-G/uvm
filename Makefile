# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 11:41:12 by ecarvalh          #+#    #+#              #
#    Updated: 2024/01/30 11:46:30 by ecarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
CFLAGS	= -Werror -Wextra -Wall
SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:%.c=objs/%.o)
NAME	= uxnemu

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM)r objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

objs/%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: all clean fclean re
