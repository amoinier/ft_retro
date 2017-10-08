# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 09:41:50 by amoinier          #+#    #+#              #
#    Updated: 2017/10/08 19:52:34 by amoinier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = ft_retro

SRCDIR = srcs/

SRCS = 	$(SRCDIR)main.cpp \
		$(SRCDIR)AEntity.cpp \
		$(SRCDIR)ASpaceShip.cpp \
		$(SRCDIR)D7.cpp \
		$(SRCDIR)Enemy.cpp \
		$(SRCDIR)Game.cpp \
		$(SRCDIR)Hero.cpp \
		$(SRCDIR)Vor_cha.cpp \
		$(SRCDIR)Weapon.cpp \
		$(SRCDIR)Bullet.cpp \
		$(SRCDIR)Carrier.cpp

OBDIR = objs/

OBJS = 	main.o \
		AEntity.o \
		ASpaceShip.o \
		D7.o \
		Enemy.o \
		Game.o \
		Hero.o \
		Vor_cha.o \
		Weapon.o \
		Bullet.o \
		Carrier.o


OBCC = $(addprefix $(OBDIR),$(OBJS))

LIB = -lncurses

all: $(NAME)

folder:
	mkdir -p $(OBDIR)

$(NAME): folder $(OBCC)
	clang++ $(FLAG) $(OBCC) -I incs/ $(LIB) -o $(NAME)

$(OBDIR)%.o: $(SRCDIR)%.cpp
	clang++ $(FLAG) -I incs/ $^ -c -o $@

clean: folder
	rm -f $(OBCC)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean folder fclean re

re: fclean all
