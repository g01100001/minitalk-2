/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putphex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:26:48 by gomandam          #+#    #+#             */
/*   Updated: 2025/03/21 22:59:17 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_phex_recursive(unsigned long n) //unsigned long since void * is used
{
	int		i;
	char	*base;

	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	base = "0123456789abcdef";
	if (n >= 16)
		i = i + ft_phex_recursive(n / 16);
	i = i + ft_putchar(base[n % 16]);
	return (i);
}

int	ft_putphex(void *n) //from uint changed to (void *)
{
	int	i;

	i = 0;
	write(1, "0x", 2);
	i = ft_phex_recursive((unsigned long)n);
	return (i + 2);
}
// unsigned long accomodates the void *

int	ft_printphex(va_list arguments)
{
	void	*format;

	format = va_arg(arguments, void *);
	if (!format)
		return (ft_putstr("(nil)"));
	return (ft_putphex(format));
}

//So the limit is the integer
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
// TESTING FOR limits.h IN ULONG_MAX
/*
int	main(void)
{
	void *test;
	
	test = (void *)ULONG_MAX;
	ft_putphex(test);
	return (0);
} */
