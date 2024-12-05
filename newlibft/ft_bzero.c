/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:43:12 by vdunatte          #+#    #+#             */
/*   Updated: 2023/10/19 20:46:15 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*s, size_t	n)
{
	char	*s2;

	s2 = s;
	while (n--)
	{
		s2[n] = '\0';
	}
}

/*
int main()
{
	char s[] = "chocapic";
	ft_bzero(s, 4);
	printf("la reponse est %d%d%d%d suite = %s", s[0], s[1], s[2], s[3], s + 4);
}
*/