/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:12:12 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/06/05 17:30:53 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{

	int	i;
	int	printed;
	va_list	args;

	va_start(args, *format);
	i = 0;
	printed = 0;
	while (*format)
	{
		if ((char *)(format + i) == '%')
			printed += ft_printargs(format[++i], printed);
		else
			printed += ft_printchar(format[i], printed);
		i++;
	}
	return (printed);
	va_end(args);
}

int	ft_printchar(const char c, int i)
{
	write(1, &c, sizeof(char));
	i++;
	return (i);
}

int ft_printargs(char *format, va_list(args))
{
	int	printed;

	printed = 0;
	if (c == '%')
		ft_printchar('%', printed);
	else if (c == 'd' || c == 'i')
		ft_printnum(*args, int);
	else if (c == 'u')
		ft_print_unsignednum(*args, i);
	else if (c == 'x' || c == 'X')
		ft_printhexa(*args, i);
	else if (c == 's')
		ft_printstring(*args, i);
	else if (c == 'c')
		ft_printchar(*args, i);
	else if (c == 'p')
		ft_printpointer(*args, i);
	return (printed);
}
