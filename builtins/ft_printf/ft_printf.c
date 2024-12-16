/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 06:32:33 by jkerthe           #+#    #+#             */
/*   Updated: 2023/11/17 12:27:25 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdi(const char test, va_list args)
{
	int	taillem;

	taillem = 0;
	if (test == 'd' || test == 'i')
		taillem = ft_printnbr(va_arg(args, int));
	if (test == 'c')
		taillem = ft_printchar(va_arg(args, int));
	if (test == 's')
		taillem = ft_prints(va_arg(args, char *));
	if (test == 'u')
		taillem = ft_print_unsigned(va_arg(args, unsigned int));
	if (test == '%')
		taillem = ft_printchar('%');
	if (test == 'x' || test == 'X')
		taillem = ft_print_hex(va_arg(args, unsigned int), test);
	if (test == 'p')
		taillem = ft_print_ptr(va_arg(args, unsigned long long));
	return (taillem);
}

int	ft_printf(const char *test, ...)
{
	int				i;
	int				taillem;
	va_list			args;

	va_start (args, test);
	taillem = 0;
	i = 0;
	while (test[i])
	{
		if (test[i] == '%')
		{
			i++;
			taillem += ft_printdi(test[i], args);
			i++;
		}
		else
		{
			taillem += ft_printchar(test[i]);
			i++;
		}
	}
	va_end(args);
	return (taillem);
}
/*
#include <stdio.h>
int	main()
{
	unsigned int c = 321512;
	printf("j'qime %x, le chocolat \n", c);
	ft_printf("j'qime %X le chocolat" , c);
}*/
