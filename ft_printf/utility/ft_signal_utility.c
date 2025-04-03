/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:13:33 by gomandam          #+#    #+#             */
/*   Updated: 2025/04/01 16:05:53 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Functions for auxiliary components and bonus
#include "../../minitalk.h"

/*
        For ft_kill(pid_t, SIGUSR#) use the following:
                if (info -> si_pid)
                        server = info -> si_pid;
*/
void	ft_kill(pid_t pid, int sigusr_nbr)
{
	if (kill(pid, sigusr_nbr) < 0)
	{
		ft_printf("Transmission failed. Check Process-ID.\n");
		ft_printf("Or perhaps, reflect on your life choices.\n");
		exit(EXIT_FAILURE);
	}
}

//end_handler sample function by oceano
/*
void	affirmation(int signumber)
{
	fputs("\nTransmission Complete. Don't lose hope.", stdout);
	exit(EXIT_SUCCESS);
}
*/
