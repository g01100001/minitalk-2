/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:18:25 by gomandam          #+#    #+#             */
/*   Updated: 2025/03/05 23:49:12 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Bitwise operation

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		b;
	int		i;
	char	binary;
	int 		a = 10968; // 'int' for decimal conversion
	
	i = 15;
	//10968 in binary is 0010101011011000
	//0000000000000010
	//0000000000000000 = 0
	//0000000000000001 = 1
	//      printf("10968 in binary is %b \n", a);
	while (i >= 0)
	{
		b = ((a >> i) & 1);
		printf("%d", b);
		i--;
	}
	printf("\n________\n\n");
	i = 15;
	while (i >= 0)
	{
		binary = ((a >> i) & 1) + 48; // +48 or +'0' implies bits to char
		write(1, &binary, 1);
		i--;
	}
	write(1, "\n", 1);
	return (0);
}
