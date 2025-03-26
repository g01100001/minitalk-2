/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:22:23 by gomandam          #+#    #+#             */
/*   Updated: 2024/11/10 21:42:49 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
//needs to return an int due to printf specifications

int	ft_printchar(va_list arguments, char c)
{
	char	format;

	if (c == '%')
		format = '%';
	else
		format = va_arg(arguments, int);
	ft_putchar(format);
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	int	c;
	c = '\n';

	ft_putchar(c);
	printf("%c %c %c ", '0', 0, '1');
	return (0);
}*/
