/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemplo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:16:07 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/06/08 14:09:19 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int	ft_max(int num_args, ...);
void	ft_printf(char *placeholders, ...);

int	main(void)
{
	ft_printf("ddfd", 4, 2, 10.5, 3);
	ft_printf("fdfdf", 1.1, 0, 2.2, 5, 3.2);

	return (0);
}

void	ft_printf(char *placeholders, ...)
{
	int	num_args;
	int	i;
	int	x;
	double	z;

	// Check placeholders length
	num_args = strlen(placeholders);
	va_list	args;
	// Start va_list(list name, first parameter before ...)
	va_start(args, placeholders);
	i = 0;
	while (i < num_args)
	{
		if (placeholders[i] == 'd')
		{
			x = va_arg(args, int);
			printf("%d\n", x);
		}
		else if (placeholders[i] == 'f')
		{
			z = va_arg(args, double);
			printf("%f\n", z);
		}
		i++;
	}
	va_end(args);
}


/*
int main()
{
	int	max_num;

	max_num = ft_max(7, 25, 3, 120, 10, 12, 14, 160);
	printf("max_num: %d\n", max_num);

	return (0);
}*/

int	ft_max(int num_args, ...)
{
	// Creates a new list of variable arguments, called args.
	va_list	args;

	// Va_start uses as param, the name of our va_list (args) and the
	//		first parameter before "...", aka the mandatory argument.
	va_start(args, num_args);

	int	i;
	int	x;
	int	max;

	i = 0;
	max = 0;
	while  (i < num_args)
	{
		// Takes as params, va_list name (args), and type of param used (int).
		x = va_arg(args, int);
		if (i == 0)
			max = x;
		else if (x > max)
			max = x;
		i++;
	}
	va_end(args);
	return (max);
}
