/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:54:06 by vdunatte          #+#    #+#             */
/*   Updated: 2023/10/28 04:20:44 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_okey(char *str, char *to_find, size_t len)
{
	while (*to_find && *str && len--)
		if (*str++ != *to_find++)
			return (0);
	return (*to_find == '\0');
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	i = 0;
	if (!little[i])
		return (((char *)big) + i);
	while (big[i] && len)
	{
		if (ft_okey(((char *)big) + i, (char *)little, len))
			return (((char *)big) + i);
		i++;
		len--;
	}
	return (0);
}
