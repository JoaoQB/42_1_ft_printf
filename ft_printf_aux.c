/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:11:30 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/06/15 12:00:03 by jqueijo-         ###   ########.fr       */
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

int	ft_printnbr_base(int nbr, char *base)
{
	int		base_value;
	int		printed;

	base_value = 0;
	printed = 0;
	while (base[base_value])
		base_value++;
	if (nbr < 0 && base == "0123456789")
	{
		if (nbr == -2147483648)
			return (write(1, "-2147483648", 11));
		printed += ft_printchar('-');
		nbr = -nbr;
	}
	if (nbr < base_value)
		printed += ft_printchar(base[nbr]);
	else if (nbr >= base_value)
	{
		printed += ft_printnbr_base(nbr / base_value, base);
		printed += ft_printnbr_base(nbr % base_value, base);
	}
	return (printed);
}

// Function to check which type of arg.

/*int	ft_printnum(int x, int i)
{va_list
	if (x < 0)
	{
		i += ft_printchar();
		if (x == -2147483648)
		{
			i += write(1, "2", sizeof(char));
			x = 147483648;
		}
		x = -x;
	}
	else if (x >= 10)
	{
		ft_printnum(x / 10, i);
		x = x % 10 + '0';
		i += write(1, &x, sizeof(char));
	}
	else
	{
		x = x + '0';
		i += write(1, &x, 1);
	}
}

int	ft_printstring(char *str, int i)
{}

int	ft_printunnum(unsigned int x, int i)
{}

int	ft_printhexa()
{}

int	ft_printpointer(void *, int i)
{}*/
