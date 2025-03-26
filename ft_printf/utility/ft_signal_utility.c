/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:13:33 by gomandam          #+#    #+#             */
/*   Updated: 2025/03/21 22:33:03 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Functions for auxiliary components and bonus
#include "../../minitalk.h"

/*
        For ft_kill(pid_t, SIGUSR#) use the following:
                if (info -> si_pid)
                        server = info -> si_pid;
*/
void	ft_kill(pid_t pid, int signumber)
{
	if (kill(pid, signumber) < 0)
	{
		fputs("Transmisison failed.\n", stderr);
		fputs("Reflect on your life choices.\n", stderr);
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
