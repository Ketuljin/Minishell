/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:58:14 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/21 14:51:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

char	*delete_sl(char	*content)
{
	int		cpt;
	char	*stock;

	cpt = 0;
	cpt = count_slash(content);
	stock = malloc(sizeof(char) * cpt +1);
	copy_slash(content, stock);
	return (stock);
}

void	copy_slash(char *content, char *stock)
{
	int	i;
	int	cpt;

	cpt = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == '/')
		{
			stock[cpt] = content[i];
			cpt++;
			i++;
			while (content[i] == '/')
				i++;
		}
		else
		{
			stock[cpt] = content[i];
			cpt++;
			i++;
		}
	}
	stock[cpt] = '\0';
}
