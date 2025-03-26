/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:26:48 by gomandam          #+#    #+#             */
/*   Updated: 2024/11/14 00:16:58 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_hex_recursive(unsigned int n, char type)
{
	int		i;
	char	*hex;

	i = 0;
	hex = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (type == 'x')
		hex = "0123456789abcdef";
	else if (type == 'X')
		hex = "0123456789ABCDEF";
	if (n >= 16)
		i = i + ft_hex_recursive(n / 16, type);
	i = i + ft_putchar(hex[n % 16]);
	return (i);
}

int	ft_printhex(va_list arguments, char type)
{
	unsigned int	format;

	format = va_arg(arguments, unsigned int);
	return (ft_hex_recursive(format, type));
}

//Do I need to typecast in to long? You only need an integer to convert
//So the limit is the integer.
/*int	main(void)
{
	unsigned int	number;

	number = 42042042;
	write(1, "Memory Address:\n", 16);
	ft_puthex(number, 'x');
	write(1, "\n", 1);
	ft_puthex(number, 'X');
	write(1, "\n", 1);
	ft_hex_recursive(number, 'x');
	write(1, "\n", 1);
	ft_hex_recursive(number, 'X');
	write(1, "\n", 1);
	write(1, "\nHexadecimal:\n", 14);
	ft_hexadecimal(number, 'X');
	write(1, "\n", 1);
	ft_hexadecimal(number, 'x');
	write(1, "\n", 1);
	return (0);
}*/