/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:05:58 by gomandam          #+#    #+#             */
/*   Updated: 2025/04/17 04:03:35 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _POSIX 10000 //POSIX (IEEE Std 1003.1-2001) valid range 1->1e6

# include "./ft_printf/ft_printf.h" //ft_printf dependencies
# include <unistd.h> //write, pause
# include <signal.h> //signal functions
# include <stdlib.h> //process control, EXIT_SUCCESS
# include <stdatomic.h> //volatile sig_atomic_t
# include <sys/types.h> //pid_t ProcessID
# include <stdio.h> //tests
# include <limits.h> //variable constants. e.g. CHAR_BIT
# include <string.h> //calloc (reprised)
void	ft_kill(pid_t pid, int signumber);
//void    affirmation(int signumber);

#endif
