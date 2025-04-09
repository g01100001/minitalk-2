/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:19:29 by gomandam          #+#    #+#             */
/*   Updated: 2025/04/09 12:48:58 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//SERVER: Listener of the client, and receives bits interpreted as signals.

#include "minitalk.h"

void	signal_handler(int sig_bit, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	c = 0;

	(void)context;
	if (sig_bit == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == CHAR_BIT)
	{
		if (c == '\0')
			ft_printf("End of message.", c);
		else
			ft_printf("%c", c);
		bit = 0;
		c = 0;
		ft_kill(info->si_pid, SIGUSR1);
	}
}

void	signal_treatment(void)
{
	struct sigaction	sail;

	sail.sa_sigaction = signal_handler;
	sail.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sail.sa_mask);
	if (sigaction(SIGUSR1, &sail, NULL) == -1)
	{
		ft_printf("Error: sigaction SIGUSR1\n");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sail, NULL) == -1)
	{
		ft_printf("Error: sigaction SIGUSR2\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

	(void)argv;
	if (!(argc == 1))
		return (ft_printf("Error: Paramater Unnecessary."), EXIT_FAILURE);
	server_pid = getpid();
	ft_printf("Server Process-ID: %d\n", server_pid);
	signal_treatment();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
/*
signal(int signum, void(*handler)(int)) tells the OS what to do 
  when a signal arrives
	1. signum, signal number to be handled SIGUSR1 or SIGUSR2
	2, handler, function called when signal is received
*/
/*
	NOTE: Implement Signal Treatmeant the same as Xyckens github
		1. Study sigaction, purpose and utilization

void	signal_treatment(void) //fails if either sigusr1 & 2 are invalid
{
	struct sigaction	action;

	action.sa_handler = &handler;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		exit(1);
}
*/
