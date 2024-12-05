/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:37:55 by vdunatte          #+#    #+#             */
/*   Updated: 2023/11/18 01:22:13 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	taille(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			n++;
		while (s[i] != c && s[i])
			i++;
	}
	return (n);
}

static char	*ft_strdup2(const char *s, char c)
{
	int		i;
	char	*s2;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	s2 = malloc((i + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**s2;

	s2 = malloc((taille(s, c) + 1) * sizeof(char *));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			s2[j++] = ft_strdup2(&s[i], c);
		while (s[i] != c && s[i])
			i++;
	}
	s2[j] = NULL;
	return (s2);
}

/*
int main()
{
	char *s = "hello!zzzzzzzz";
	char **da = ft_split(s, 'z');
	int i = 0;
	while (da[i])
	{
		printf("[main]%s\n", da[i]);
		i++;
	}
	printf("%s", da[i]);
	return 0;
}
*/
