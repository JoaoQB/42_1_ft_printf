/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:53:45 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/06/10 16:38:16 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	/*else if (c == 'd' || c == 'i')
		ft_printnum(va_arg(l, int), i);
	else if (c == 'u')
		ft_print_unnum(va_arg(l, unsigned int), i);
	else if (c == 'x' || c == 'X')
		ft_printhexa(va_arg(l, int), i);
	else if (c == 'p')
		ft_printpointer(va_arg(l, *void), i);*/
	return (printed);
}
