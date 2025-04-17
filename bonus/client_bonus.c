/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 02:43:36 by gomandam          #+#    #+#             */
/*   Updated: 2025/04/17 03:51:58 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

volatile sig_atomic_t	g_acknowledged = 0;

void	sigusr1_handler(int signal_nbr)
{
	(void)signal_nbr;
	g_acknowledged = 1;
}

void	send_bits(int pid, int value, int bit_count)
{
	int	bit;

	bit = 0;
	while (bit < bit_count)
	{
		if ((value >> bit) & 1)
			ft_kill(pid, SIGUSR1);
		else
			ft_kill(pid, SIGUSR2);
		usleep(100);
		while (!g_acknowledged)
			pause();
		g_acknowledged = 0;
		bit++;
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_bits(pid, message[i], 8);
		i++;
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Utilization: ./client <server-pid> \"message\"\n");
		return (EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Error: Invalid server PID.\n");
		return (EXIT_FAILURE);
	}
	sa.sa_handler = sigusr1_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error: Signal setup failed.\n");
		return (EXIT_FAILURE);
	}
	send_bits(server_pid, ft_strlen(argv[2]), 32); // Send length
	send_message(server_pid, argv[2]); // Send message
	return (EXIT_SUCCESS);
}
