/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:05:36 by gomandam          #+#    #+#             */
/*   Updated: 2025/03/04 20:08:36 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "./ft_printf/ft_printf.h"

int	main(int argc, char *argv[])
{
	(void)argc;

	ft_printf("[1-byte == 8-bit] value of character bit = %d\n", CHAR_BIT);
	ft_printf("ATOI: %d", ft_atoi(argv[1]));
	
	while (1)
		pause();
	return (0);
}
