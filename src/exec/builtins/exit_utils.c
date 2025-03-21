/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:21:17 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/21 21:08:41 by jkerthe          ###   ########.fr       */
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

int	size_comp(char *content, char *env)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (content[i] && content[i] != '=')
		i++;
	while (env[y] && env[y] != '=')
		y++;
	if (y >= i)
		return (y);
	else
		return (i);
}
