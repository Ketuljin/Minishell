/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:45:56 by vdunatte          #+#    #+#             */
/*   Updated: 2023/10/19 04:10:30 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned const char	*src1;
	unsigned char		*dest1;

	i = 0;
	src1 = src;
	dest1 = dest;
	if (src1 > dest1)
	{
		while (i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	if (src1 < dest1)
	{
		while (n--)
		{
			dest1[n] = src1[n];
		}
	}
	return (dest);
}

/*
int main ()
{
	char	str[] = "asughaukigh";
	printf("%s", (char *)ft_memmove(str[2], str[3], 5));
}
*/