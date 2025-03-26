/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:35:28 by gomandam          #+#    #+#             */
/*   Updated: 2024/11/14 01:33:15 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_putstr(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (*s != '\0')
		{
			write(1, s, 1);
			s++;
			i++;
		}
	}
	return (i);
}

int	ft_printstr(va_list arguments)
{
	char	*format;

	format = va_arg(arguments, char *);
	return (ft_putstr(format));
}
/*
int	main(void)
{
	char	*str;

	str = "test tickles\n";
	write(1, str, 13);
	ft_putstr(str);
}
*/
