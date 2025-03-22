/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:36:28 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/22 20:56:11 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdarg.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}

static bool	joinv(int count, char **ret, va_list *arg, size_t len)
{
	char	*s;

	if (count != 0)
		s = va_arg(*arg, char *);
	if (count == 0 || s == NULL)
	{
		*ret = malloc(len + 1);
		if (*ret == NULL)
			return (false);
		(*ret)[len] = '\0';
		return (true);
	}
	if (!joinv((count * (count > 0)) - 1, ret, arg, len + ft_strlen(s)))
		return (false);
	while (*s)
		(*ret)[len++] = *s++;
	return (true);
}

char	*ft_strjoinv(int count, ...)
{
	char	*s;
	va_list	arg;

	va_start(arg, count);
	if (!joinv(count, &s, &arg, 0))
		return (va_end(arg), NULL);
	return (va_end(arg), s);
}
