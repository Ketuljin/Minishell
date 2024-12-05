/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:15:03 by vdunatte          #+#    #+#             */
/*   Updated: 2024/12/05 21:06:29 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabfree(char **tab)
{
	int	i;
	int	size;

	i = 0;
	size = ft_tablen(tab);
	while (i++ < size)
		free(tab[i]);
	free(tab);
}