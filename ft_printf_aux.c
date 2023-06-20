/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:11:30 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/06/20 14:56:41 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	return (write(1, &c, sizeof(char)));
}

int	ft_printstring(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_printchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_printnbr(int nbr)
{
	int		printed;

	printed = 0;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			return (write(1, "-2147483648", 11));
		printed += ft_printchar('-');
		printed += ft_printnbr(-nbr);
	}
	else if (nbr >= 10)
	{
		printed += ft_printnbr(nbr / 10);
		printed += ft_printnbr(nbr % 10);
	}
	else if (nbr >= 0 && nbr <= 9)
		printed += ft_printchar(nbr + '0');
	return (printed);
}

int	ft_printnbr_base(unsigned int nbr, char *base)
{
	unsigned int		base_value;
	unsigned int		printed;

	base_value = 0;
	printed = 0;
	while (base[base_value])
		base_value++;
	if (nbr < base_value)
		printed += ft_printchar(base[nbr]);
	else if (nbr >= base_value)
	{
		printed += ft_printnbr_base(nbr / base_value, base);
		printed += ft_printnbr_base(nbr % base_value, base);
	}
	return (printed);
}

int	ft_printptr(unsigned int i)
{
	if (i == 0)
		return (ft_printstring("(nil)"));
	else
		return (ft_printstring("0x") + ft_printnbr_base(i, "0123456789abcedf"));
}
