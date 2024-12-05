/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:29:08 by vdunatte          #+#    #+#             */
/*   Updated: 2023/10/28 01:59:33 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_valabs(int i )
{
	unsigned int	j;

	j = 0;
	if (i > 0)
		j = i;
	if (i < 0)
		j = -i;
	return (j);
}

static size_t	ft_lenint(unsigned int i)
{
	size_t	c;

	c = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	n1;
	int				i;

	n1 = ft_valabs(n);
	i = ft_lenint(n1);
	if (n < 0)
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	if (n1 == 0)
		str[i] = '0';
	while (n1 > 0)
	{
		str[i--] = n1 % 10 + '0';
		n1 = n1 / 10;
	}
	if (n < 0)
		str[i] = '-';
	return (str);
}
