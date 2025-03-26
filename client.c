/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:21:38 by gomandam          #+#    #+#             */
/*   Updated: 2025/03/26 13:28:08 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//CLIENT: Talks to the server and transmits bits in series of signals.

#include "minitalk.h"

void	ft_fax(pid_t server_pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if ((c & (0b1 << bit)) != 0)
			ft_kill(server_pid, SIGUSR1);
		else
			ft_kill(server_pid, SIGUSR2);
		usleep(_POSIX);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	char	*message;
	pid_t	server_pid;

	if (!(argc == 3))
	{
		ft_printf("Utilization: ./client <server-pid> \"message\"\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		message = argv[2];
		while (*message)
			ft_fax(server_pid, *message++);
		ft_fax(server_pid, '\n');
	}
	return (EXIT_SUCCESS);
}

//facsimile (defn.) copy and digital transmission of a material.
