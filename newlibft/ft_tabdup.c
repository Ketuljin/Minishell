/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 03:58:40 by vdunatte          #+#    #+#             */
/*   Updated: 2024/12/13 21:46:51 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **src_tab)
{
	int		i;
	char	**des_tab;

	i = 0;
	des_tab = malloc((ft_tablen(src_tab) + 1) * sizeof(char *));
	while (src_tab != NULL && src_tab[i] != NULL)
	{
		des_tab[i] = ft_strdup(src_tab[i]);
		i++;
	}
	des_tab[i] = NULL;
	return (des_tab);
}
