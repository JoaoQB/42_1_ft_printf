/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:13:58 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/06/20 14:56:28 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h> // memory allocation
# include <stdarg.h> // va_lists
# include <string.h> // String manipulation
# include <stddef.h> // Types and macros like NULL and size_t
# include <stdio.h> // Printf
# include <unistd.h> // System calls, write
# include <limits.h> // Limits, for testing

int	ft_printf(const char *format, ...);
int	ft_check_args(char c, va_list l);
int	ft_printchar(char c);
int	ft_printstring(char *str);
int	ft_printnbr_base(unsigned int nbr, char *base);
int	ft_printnbr(int nbr);
int	ft_printptr(unsigned int i);

#endif
