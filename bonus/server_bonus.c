/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 02:44:20 by gomandam          #+#    #+#             */
/*   Updated: 2025/04/17 04:02:19 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

typedef struct s_data
{
	int		bit_count;
	int		char_build;
	int		length;
	int		length_bits;
	char	*message;
	int		message_pos;
}			t_data;

static t_data	g_data;

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	total;

	total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	str = malloc(total);
	if (!str)
		return (NULL);
	memset(str, 0, total);
	return (str);
}

void	signal_handler(int sig_bit, siginfo_t *info, void *context)
{
	(void)context;
	if (g_data.length_bits < 32) // Receiving the length
	{
		if (sig_bit == SIGUSR1)
			g_data.length |= (0x01 << g_data.length_bits);
		g_data.length_bits++;
	}
	else // Receiving the message
	{
		if (sig_bit == SIGUSR1)
			g_data.char_build |= (0x01 << g_data.bit_count);
		g_data.bit_count++;
		if (g_data.bit_count == 8) // Character complete
		{
			g_data.message[g_data.message_pos++] = g_data.char_build;
			g_data.bit_count = 0;
			g_data.char_build = 0;
		}
	}
	if (g_data.length_bits == 32 && g_data.message == NULL) // Allocate memory
	{
		g_data.message = ft_calloc(g_data.length + 1, sizeof(char));
		if (!g_data.message)
			exit(EXIT_FAILURE);
	}
	if (g_data.message_pos == g_data.length) // End of message
	{
		ft_printf("Message: %s\n", g_data.message);
		free(g_data.message);
		g_data = (t_data){0}; // Reset global structure
		ft_kill(info->si_pid, SIGUSR2);
	}
	else
		ft_kill(info->si_pid, SIGUSR1); // Acknowledge bit received
}

void	signal_treatment(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	ft_printf("Server Process-ID: %d\n", getpid());
	signal_treatment();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
