# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 17:30:52 by gomandam          #+#    #+#              #
#    Updated: 2025/03/21 23:10:04 by gomandam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC = 	server.c \
	client.c \
	ft_printf/ft_printf.c \
	ft_printf/utility/ft_putchar.c \
	ft_printf/utility/ft_puthex.c \
	ft_printf/utility/ft_putnbr.c \
	ft_printf/utility/ft_putphex.c \
	ft_printf/utility/ft_putstr.c \
	ft_printf/utility/ft_atoi.c \
	ft_printf/utility/ft_signal_utility.c \

OBJECTS = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	@ echo "Execute: Minitalk."
	@ ar rcs $(NAME) $(OBJECTS) > /dev/null 2>&1

# @ echo " " -> prints description
# @ COMMAND > /dev/null 2>&1 -> silences notifications

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

