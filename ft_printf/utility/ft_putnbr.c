/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:47:21 by gomandam          #+#    #+#             */
/*   Updated: 2024/11/14 01:33:29 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(long n)
{
	long	nbr;
	int		i;
	int		storage;
	char	digits[12];

	storage = 0;
	nbr = (long)n;
	if (nbr < 0)
	{
		storage = (int)write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr == 0)
		return (write(1, "0", 1), 1);
	i = 0;
	while (nbr > 0)
	{
		digits[i] = (nbr % 10) + '0';
		i++;
		nbr = nbr / 10;
	}
	storage = storage + i;
	while (i-- > 0)
		write(1, &digits[i], 1);
	return (storage);
}
// write data type = size t, so typecast it to int
// must return the length of integer accounted
// storage will store the counted numbers after printing it on reverse
// char digits is 10 max int is -2147483648 (10-digits)
// but (negative) write is being accounted as an INT, so (12-digits)

int	ft_printnbr(va_list arguments)
{
	int	format;

	format = va_arg(arguments, int);
	return (ft_putnbr(format));
}

// ft_putnbr unsigned nbr -> ft_printdecimal

int	ft_printdeci(va_list arguments)
{
	unsigned int	format;

	format = va_arg(arguments, unsigned int);
	return (ft_putnbr(format));
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	printf("argument counter %d\n", argc);
	while (argc > i)
	{
	printf("arugment %d is %s.\n", i, argv[i]);
	ft_putnbr(atoi(argv[i]));
	write(1, "\n", 1);
	i++;
	}
	return (0);
}
*/
// ./a.out 1 -2 +3 04 5
/*int   main(void)
{
	int	number;
	number = 42000;
	ft_putnbr(number);
	write(1, "\n", 1);
	return (0);
}*/
