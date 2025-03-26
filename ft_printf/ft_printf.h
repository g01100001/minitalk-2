/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:33:25 by gomandam          #+#    #+#             */
/*   Updated: 2025/03/04 19:02:29 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(int c);
int		ft_printchar(va_list arguments, char c);

size_t	ft_putstr(const char *s);
int		ft_printstr(va_list arguments);

int		ft_putnbr(long n);
int		ft_printnbr(va_list arguments);

int		ft_printdeci(va_list arguments);

//int		ft_puthex(unsigned int n, char type);
int		ft_hex_recursive(unsigned int n, char type);
int		ft_printhex(va_list arguments, char type);

int		ft_phex_recursive(unsigned long n);
int		ft_putphex(void *n);
int		ft_printphex(va_list arguments);
//int		ft_hexadecimal(unsigned int n, char type);

int		ft_type(char const c, va_list arguments);
int		ft_traverse(va_list arguments, char const *format);
int		ft_printf(const char *format, ...);

int		ft_atoi(const char *nptr);

#endif
/*
 #include <limits.h> //INT min-max, UINT max, LONG min-max, ULONG max 
 #include <stdarg.h> //variadic functions
 #include <stdlib.h> //string conversion 
 #include <unistd.h> //write, null pointer, size_t and other typedef
*/
