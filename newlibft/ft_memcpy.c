/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:45:14 by vdunatte          #+#    #+#             */
/*   Updated: 2023/10/19 03:35:59 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*str;
	char		*dest1;

	i = 0;
	str = src;
	dest1 = dest;
	if (dest1 == NULL && str == NULL)
		return (NULL);
	while (i < n)
	{
		dest1[i] = str[i];
		i++;
	}
	return (dest);
}

/*
int main ()
{
	char	str[] = "asughaukigh";
	char	dst[10000] = {};
	printf("%s", (char *)ft_memcpy(dst, str, 5));
}
*/