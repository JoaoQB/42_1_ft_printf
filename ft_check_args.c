/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:53:45 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/06/10 18:26:01 by jqueijo-         ###   ########.fr       */
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
		printed += ft_printstring(va_arg(l, char *));
	else if (c == 'd' || c == 'i')
		printed += ft_printnbr_base(va_arg(l, int), "0123456789");
	else if (c == 'x')
		printed += ft_printnbr_base(va_arg(l, int), "0123456789abcedf");
	else if (c == 'X')
		printed += ft_printnbr_base(va_arg(l, int), "0123456789ABCDEF");
	/*else if (c == 'u')
		ft_print_unnum(va_arg(l, unsigned int), i);
	else if (c == 'p')
		ft_printpointer(va_arg(l, *void), i);*/
	return (printed);
}
