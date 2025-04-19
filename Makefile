# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 17:30:52 by gomandam          #+#    #+#              #
#    Updated: 2025/04/20 01:55:53 by gomandam         ###   ########.fr        #
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
	@ echo "MINITALK Executed Successfully."
	@ ar rcs $(NAME) $(OBJECTS) > /dev/null 2>&1

# @ echo " " -> prints description
# @ COMMAND > /dev/null 2>&1 -> silences notifications

%.o : %.c
	@ echo "Compilation Complete. For the horde."
	@ $(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1

clean:
	@ $(RM) $(OBJECTS) > /dev/null 2>&1
	@ echo "Power Overwhelming. Objects Exterminated."

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

