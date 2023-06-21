/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:22:04 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/06/21 11:25:11 by jqueijo-         ###   ########.fr       */
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
	unsigned int	base_value;
	unsigned int	printed;

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

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		ft_printchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_printchar(char c)
{
	return (write(1, &c, sizeof(char)));
}

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

int	main()
{
	float	x = 37.7;
	ft_printf("%d\n", x);

	return (0);
}
