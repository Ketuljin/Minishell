/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:21:17 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/20 21:27:00 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

long long int	ft_atoie(const char	*nptr)
{
	long long int	n;
	long long int	r;

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
