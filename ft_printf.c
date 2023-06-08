/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:12:12 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/06/08 16:34:49 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{

	int	i;
	int	printed;

	// New list of variable arguments.
	va_list	args;

	// Start the arguments list.
	va_start(args, format);
	i = 0;
	printed = 0;
	while (*format)
	{
		// If conversion sign, check argument parameter (next index).
		if (format[i] == '%')
			printed += check_args(format[++i], args, printed);
		// If not, print char.
		else
			printed += ft_printchar(format[i], printed);
		i++;
	}
	va_end(args);
	return (printed);
}

// Probably will need to change function to take in variadic argument.
int	ft_printchar(const char c, int i)
{
	i += write(1, &c, sizeof(char));
	return (i);
}

// Function to check which type of arg.
int check_args(char c, va_list l, int i)
{
	if (c == '%')
		ft_printchar('%', i);
	else if (c == 'd' || c == 'i')
		ft_printnum(va_arg(l, int), i);
	else if (c == 'u')
		ft_print_unnum(va_arg(l, unsigned int), i);
	else if (c == 'x' || c == 'X')
		ft_printhexa(va_arg(l, int), i);
	else if (c == 's')
		ft_printstring(va_arg(l, char), i);
	else if (c == 'c')
		ft_printchar(va_arg(l, char), i);
//	else if (c == 'p')
//		ft_printpointer(va_arg(l, *void), i);
	return (i);
}

int	main(void)
{
	ft_printf("this is %cest nr %d\n", 't', 1);
	return (0);
}
