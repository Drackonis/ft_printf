# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkergast <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:06:19 by rkergast          #+#    #+#              #
#    Updated: 2019/05/21 19:15:48 by dieroyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror 

HEADERS = libft/libft.h

LIBFT = libft/libft.a

SRC = ft_printf.c \
	  ft_printf_f.c \
	  ft_printf_f2.c \
	  ft_putnbr_base.c \
	  ft_printf_s.c \
	  ft_getconv.c

SRC_LIBFT = libft/ft_atoi.c \
			libft/ft_putchar.c \
			libft/ft_putstr.c \
			libft/ft_strdup.c \
			libft/ft_putlwstr.c \
			libft/ft_putlstr.c \
			libft/ft_strlen.c

OBJ = $(SRC:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	libtool -static -o $(NAME) $(OBJ) $(LIBFT)
	ranlib $(NAME)

$(LIBFT): $(SRC_LIBFT) $(HEADERS)
	make -C libft

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -o $@ -c $< -Ilibft/

clean :
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all
