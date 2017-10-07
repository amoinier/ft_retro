# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 09:41:50 by amoinier          #+#    #+#              #
#    Updated: 2017/10/07 15:19:41 by amoinier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = ft_retro

SRCDIR = srcs/

SRCS = $(shell ls srcs/)

OBDIR = objs/

OBJS = $(SRCS:.c=.o)

LIB = -lncurses

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(FLAG) $(OBJS) $(LIB) -o $(NAME)

$(OBDIR)%.o: $(SRCDIR)%.cpp
	mkdir -p $(OBDIR)
	clang++ $(FLAG) $(SRCS) -c -o $@

clean:
	rm -f $(OBJS)
	rm -r $(OBDIR)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re

re: fclean all
