/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:24:20 by gomandam          #+#    #+#             */
/*   Updated: 2025/03/18 18:54:45 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Converts decimal to binary values

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_bitshift(unsigned int decimal)
{
	int		i;
	char	bits[32];

	i = 0;
	while (decimal > 0)
	{
		bits[i] = (decimal & 1) + '0';
		decimal >>= 1;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &bits[i], 1);
	}
}

int	main(int argc, char *argv[])
{
	int	decimal;

	if (argc != 2)
	{
		fputs("./program \"input 33 to 126 decimal\"\n", stderr);
		exit(EXIT_FAILURE);
	}
	decimal = atoi(argv[1]);
	if (decimal > 126 || decimal < 33)
	{
		fputs("Non-printable. Only between 33 and 126\n", stderr);
		exit(EXIT_FAILURE);
	}
	printf(" in binary. ");
	ft_bitshift(decimal);
	printf("\n");
	printf("Decimal '%d' in ASCII.\n", decimal);
	printf("Character is '%c'.\n", decimal);
	return (0);
}

// Printable characters are less than 127 in decimal.
