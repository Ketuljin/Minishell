/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:04:35 by jkerthe           #+#    #+#             */
/*   Updated: 2023/11/17 12:35:40 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned	long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_printchar(num + '0');
		else
		{
			ft_printchar(num - 10 + 'a');
		}
	}
}

int	ft_print_ptr(unsigned long long int ptr)
{
	int	print_length;

	print_length = 0;
	if (ptr > 0)
		print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "(nil)", 5);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}

/*
#include <stdio.h>
int	main()
{
	void *ptr;
	int *ptr1 = 0;
	ptr = &ptr1;

	printf("%p\n", &ptr);
	ft_print_ptr((long long)ptr);

}
*/