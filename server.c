/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:19:29 by gomandam          #+#    #+#             */
/*   Updated: 2025/03/25 15:25:23 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//SERVER: Listener of the client, and receives bits interpreted as signals.

#include "minitalk.h"

void	signal_handler(int sig_bit)
{
	static int	bit = 0;
	static int	c = 0;

	if (sig_bit == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

	(void)argv;
	if (!(argc == 1))
		return (fputs("Error: Remove a parameter.", stderr), EXIT_FAILURE);
	server_pid = getpid();
	ft_printf("Server ProcessID: %d\n", server_pid);
	while (argc == 1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (EXIT_SUCCESS);
}
/*
signal(int signum, void(*handler)(int)) tells the OS what to do 
  when a signal arrives
	1. signum, signal number to be handled SIGUSR1 or SIGUSR2
	2, handler, function called when signal is received
*/
