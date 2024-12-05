/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:23:11 by vdunatte          #+#    #+#             */
/*   Updated: 2023/10/18 01:23:08 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char	*nptr)
{
	int	n;
	int	r;

	n = 1;
	r = 0;
	while (*nptr == ' '
		|| *nptr == '\f'
		|| *nptr == '\n'
		|| *nptr == '\r'
		|| *nptr == '\t'
		|| *nptr == '\v')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			n = -n;
		nptr++;
	}
	while ('0' <= *nptr && *nptr <= '9')
	{
		r = r * 10 + *nptr - '0';
		nptr++;
	}
	return (r * n);
}

/*
int	main(void)
{
	int	n;

	n = ft_atoi(" --1234ab567");
	printf("%d\n", n);
	return(0);
}
*/