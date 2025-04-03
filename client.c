/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:21:38 by gomandam          #+#    #+#             */
/*   Updated: 2025/04/01 16:32:48 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//CLIENT: Talks to the server and transmits bits in series of signals.

#include "minitalk.h"

volatile sig_atomic_t	g_sigcon = 0;

void	sigusr1_handler(int signal_nbr)
{
	(void)signal_nbr;
	g_sigcon = 1;
}

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
		while (!g_sigcon)
			pause();
		g_sigcon = 0;
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	char				*message;
	pid_t				server_pid;
	struct sigaction	sail;

	if (!(argc == 3))
	{
		ft_printf("Utilization: ./client <server-pid> \"message\"\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		message = argv[2];
		sail.sa_handler = sigusr1_handler;
		sail.sa_flags = SA_RESTART;
		sigaction(SIGUSR1, &sail, NULL); /*signal(SIGUSR1, sigusr1_handler);*/
		while (*message)
			ft_fax(server_pid, *message++);
		ft_fax(server_pid, '\n');
	}
	return (EXIT_SUCCESS);
}
/*

//facsimile (defn.) copy and digital transmission of a material.

//volatile sig_atomic_t	_global = 0;
	handle global changes, sets _global upon receiving SIGUSR1;
		ft_fax waits for signal to be set before sending
		while(!_global) -> the pause is signal acknowledgment
//atomic updates - operations of single and indivisible step.
	No interruptions, the variable is read or written in one step.
	Safety in cases of multi-thread environments. 
*/