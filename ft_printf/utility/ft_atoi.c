/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 23:14:56 by gomandam          #+#    #+#             */
/*   Updated: 2025/03/14 16:02:31 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_sequence(int c)
{
	while ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	ans;

	ans = 0;
	sign = 1;
	while (ft_sequence(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		ans = ans * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(ans * sign));
}
/*
int	main(void)
{
	const char *test1 = "4242";
	const char *test2 = "--3342";
	const char *test3 = "   +90abc";
	const char *test4 = "abc123";
	const char *test5 = "-1000043";
	const char *test6 = "--+-123";

	printf("input: %s \noutput: %d\n\n", test1, ft_atoi(test1));
	printf("input: %s \noutput: %d\n\n", test2, ft_atoi(test2));
	printf("input: %s \noutput: %d\n\n", test3, ft_atoi(test3));
	printf("input: %s \noutput: %d\n\n", test4, ft_atoi(test4));
	printf("input: %s \noutput: %d\n\n", test4, ft_atoi(test5));
	printf("input: %s \noutput: %d\n\n", test4, ft_atoi(test6));
	return (0);
}
*/
//c/66fc7cef-65f0-8008-8efa-095a3393536f
/*
static int      ft_isspace(int c)
{
        int     is_blank;

        is_blank = c == ' ' || c == '\t';
        if (c == '\f' || c == '\n' || c == '\r' || c == '\v' || is_blank)
                return (1);
        return (0);
}
*/
