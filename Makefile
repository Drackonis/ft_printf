# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkergast <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:06:19 by rkergast          #+#    #+#              #
#    Updated: 2019/05/06 17:43:14 by dieroyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

CC = gcc

FLAGS = -Wall -Wextra -Werror 

HEADERS = libft/libft.h

LIBFT = libft/libft.a

SRC = ft_printf.c

SRC_LIBFT = libft/ft_atoi.c \
			libft/ft_putchar.c \
			libft/ft_putstr.c \
			libft/ft_strdup.c \
			libft/ft_putwstr 

OBJ = $(SRC:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

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
