/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:30:31 by gomandam          #+#    #+#             */
/*   Updated: 2024/11/14 02:01:57 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char const c, va_list arguments)
{
	int	result;

	result = 0;
	if (c == '%' || c == 'c')
		result = ft_printchar(arguments, c);
	else if (c == 's')
		result = ft_printstr(arguments);
	else if (c == 'd' || c == 'i')
		result = ft_printnbr(arguments);
	else if (c == 'x' || c == 'X')
		result = ft_printhex(arguments, c);
	else if (c == 'p')
		result = ft_printphex(arguments);
	else if (c == 'u')
		result = ft_printdeci(arguments);
	return (result);
}

int	ft_traverse(va_list arguments, char const *format)
{
	int	i;

	i = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			i = i + ft_type(*(format + 1), arguments);
			format = format + 2;
		}
		else
		{
			i++;
			write(1, format, 1);
			format++;
		}
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		result;

	va_start(arguments, format);
	result = ft_traverse(arguments, format);
	va_end(arguments);
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	int	x;
	int	gab;
	int	org;
	int	i;

	ft_printf("My Character: %c\n", 'F');
	printf("Std Character: %c\n", 'F');
	
	ft_printf("My String: %s", "Test Tickles.\n");
	printf("Std String: %s", "Test Tickles.\n");
	
	ft_printf("My Empty Str:%s", "");
	printf("Std Empty Str:%s", "");
	//Expected: Test (just an empty line after Test)
	
	ft_printf("\nDigits or Integer: %d %i", 42, 33);
	printf("Std Digits or Integers: %d %i\n", 42, 33);
	
	ft_printf("My Hex: %x\n", 14124124);
	ft_printf("My Hex: %X\n", 14124124);
	printf("Std Hex: %x\n", 14124124);
	printf("Std Hex: %X\n", 14124124);
	
	ft_printf("My Character: %c %c\n", 'F', 'T');
	ft_printf("My ASCII: %c %c\n", 70, 84); //ASCII
	
	x = 42;
	gab = ft_printf("Pointer Hex: %p\n", (void *)&x);
	org = printf("Pointer Hex: %p\n", (void *)&x);
	printf("org = %d, gab = %d\n", org, gab);
	//explicitly typecast to pass a pointer address, not an integer
	ft_printf("The value of CHAR_BIT: %d\n", CHAR_BIT);
	ft_printf("The value of SCHAR_MIN: %d\n", SCHAR_MIN);
	ft_printf("The value of SCHAR_MAX: %d\n", SCHAR_MAX);
	ft_printf("The value of UCHAR_MAX: %u\n", UCHAR_MAX);
	ft_printf("The value of CHAR_MIN: %d\n", CHAR_MIN);
	ft_printf("The value of CHAR_MAX: %d\n", CHAR_MAX);
	ft_printf("The value of MB_LEN_MAX: %d\n", MB_LEN_MAX);
	ft_printf("The value of SHRT_MIN: %d\n", SHRT_MIN);
	ft_printf("The value of SHRT_MAX: %d\n", SHRT_MAX);
	ft_printf("The value of USHRT_MAX: %u\n", USHRT_MAX);
	ft_printf("The value of INT_MIN: %d\n", INT_MIN);
	ft_printf("The value of INT_MAX: %d\n", INT_MAX);
	ft_printf("The value of UINT_MAX: %u\n", UINT_MAX);
	i = 42;
	ft_printf("Total Written Characters: %d\n",
			ft_printf("fourty_two:_%d_%c\n", i, i));
	return (0);
}
*/
