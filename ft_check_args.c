/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:53:45 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/06/20 16:28:32 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_args(char c, va_list l)
{
	int	printed;

	printed = 0;
	if (c == '%')
		printed += ft_printchar('%');
	else if (c == 'c')
		printed += ft_printchar(va_arg(l, int));
	else if (c == 's')
		printed += ft_printstr(va_arg(l, char *));
	else if (c == 'd' || c == 'i')
		printed += ft_printnbr(va_arg(l, int));
	else if (c == 'x')
		printed += ft_printnbr_base(va_arg(l, int), "0123456789abcdef");
	else if (c == 'X')
		printed += ft_printnbr_base(va_arg(l, int), "0123456789ABCDEF");
	else if (c == 'u')
		printed += ft_printnbr_base(va_arg(l, unsigned int), "0123456789");
	else if (c == 'p')
		printed += ft_printptr(va_arg(l, unsigned long long));
	return (printed);
}
