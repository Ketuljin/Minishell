/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:47:59 by jkerthe           #+#    #+#             */
/*   Updated: 2023/11/17 12:00:12 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	getcpt(int nb)
{
	size_t		i;

	i = 1;
	while ((nb / 10) < 0 || ((nb / 10) >= 1))
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		cpt;
	long int	num;

	num = n;
	cpt = getcpt(n);
	if (n < 0)
	{
		num *= -1;
		cpt++;
	}
	str_num = (char *)malloc(sizeof(char) * (cpt + 1));
	if (str_num == NULL)
		return (NULL);
	*(str_num + cpt) = 0;
	while (cpt--)
	{
		*(str_num + cpt) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str_num + 0) = '-';
	return (str_num);
}

int	ft_printnbr(int nb)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(nb);
	len = ft_prints(num);
	free(num);
	return (len);
}
