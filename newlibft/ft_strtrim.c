/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:37:22 by vdunatte          #+#    #+#             */
/*   Updated: 2023/11/18 01:26:55 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ok(char c, char const *set)
{
	int	i;

	i = ft_strlen(set);
	while (i--)
		if (c == set[i])
			return (1);
	return (0);
}

static size_t	ft_setd(char const *s1, char const *set)
{
	size_t	t;
	int		i;

	i = 0;
	t = 0;
	while (ft_ok(s1[i], set))
	{
		t++;
		i++;
	}
	return (t);
}

static size_t	ft_setf(char const *s1, char const *set)
{
	size_t	t;
	int		i;

	i = ft_strlen(s1) - 1;
	t = 0;
	while (ft_ok(s1[i], set))
	{
		t++;
		i--;
	}
	return (t);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	d;
	size_t	f;
	size_t	i;

	d = ft_setd(s1, set);
	f = ft_setf(s1, set);
	if (ft_strlen(s1) == d && ft_strlen(s1) == f)
	{
		s2 = malloc(1);
		s2[0] = '\0';
		return (s2);
	}
	s2 = malloc((ft_strlen(s1) - d - f + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i + d != ft_strlen(s1) - f)
	{
		s2[i] = s1[i + d];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
