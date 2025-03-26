# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 20:56:59 by gomandam          #+#    #+#              #
#    Updated: 2024/11/13 18:11:59 by gomandam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SOURCE = ft_printf.c \
	 utility/ft_putchar.c \
	 utility/ft_putstr.c \
	 utility/ft_putnbr.c \
	 utility/ft_puthex.c \
	 utility/ft_putphex.c \

OBJECTS = $(SOURCE:.c=.o) 

RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
