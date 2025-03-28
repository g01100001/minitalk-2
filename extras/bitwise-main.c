/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise-main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:39:50 by gomandam          #+#    #+#             */
/*   Updated: 2025/03/17 16:48:05 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Converts binary to decimal

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*
void	ft_binary(const char *str)
{
	int	count;
	char	bit;
	int	i;
	int	decimal;

	count = 0;
	decimal = 0;
	while (str[count] != '\0')
	{
		if (str[count] != '0' && str[count] != '1')
			exit(EXIT_FAILURE);
		decimal = decimal * 2 + (str[count] - '0');
		count++;
	}
	i = 7;
	while (i >= 0)
	{
		bit = ((decimal >> i) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
} */

void	ft_bindeci(const char *str)
{
	int	count;
	int	decimal;

	count = 0;
	decimal = 0;
	while (str[count] != '\0')
	{
		if (str[count] != '0' && str[count] != '1')
			exit(EXIT_FAILURE);
		decimal = (decimal << 1) | (str[count] - 48);
		count++;
	}
	printf("\ndecimal '%d' in ascii character is '%c'\n", decimal, decimal);
	write(1, &decimal, 1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fputs("Input binary value: \n", stderr);
		exit(EXIT_FAILURE);
	}
//	printf("Binary %s\n", argv[1]);
//	ft_binary(argv[1]);
	ft_bindeci(argv[1]);
	printf("\n");
	exit(EXIT_SUCCESS);
}
