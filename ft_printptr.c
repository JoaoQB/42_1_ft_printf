/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:02:22 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/06/20 16:30:05 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(unsigned long long i)
{
	int	printed;

	printed = 0;
	if (i >= 16)
	{
		printed += ft_putptr(i / 16);
		printed += ft_putptr(i % 16);
	}
	else
	{
		if (i <= 9)
			printed += ft_printchar(i + '0');
		else
			printed += ft_printchar((i - 10) + 'a');
	}
	return (printed);
}

int	ft_printptr(unsigned long long i)
{
	if (i == 0)
		return (ft_printstr("(nil)"));
	else
		return (ft_printstr("0x") + ft_putptr(i));
}
