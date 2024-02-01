# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 11:41:12 by ecarvalh          #+#    #+#              #
#    Updated: 2024/02/01 14:56:02 by ecarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
CFLAGS	= -Werror -Wextra -Wall
SRCS	= aux.c stk.c stkx.c uvm.c emu.c
OBJS	= $(SRCS:%.c=objs/%.o)
NAME	= emu

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM)r objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

objs/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re
