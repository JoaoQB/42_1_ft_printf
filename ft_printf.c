/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:12:12 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/06/10 16:54:43 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed;
	va_list	args;

	va_start(args, format);
	i = 0;
	printed = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			printed += ft_check_args(format[++i], args);
		else
			printed += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (printed);
}
