/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:12:12 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/26 12:31:15 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{

	int	i;
	int	print;
	va_list	args;

	va_start(args, *format);
	i = 0;
	print = 0;
	while (*format)
	{
		if (*(char *)(format + i == '%'))
		{}
		print = ft_putchar(*(format + i), print);
		i++;
	}
	return (print);
}

int	ft_putchar(const char c, int i)
{
	write(1, &c, sizeof(char));
	i++;
	return (i);
}
