/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:24:57 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/22 18:34:00 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	skip_quote_index(char *temp, char *str, int *i, int *j)
{
	char	c;

	if (str[*i] != '\'' && str[*i] != '\"')
		return (0);
	c = str[*i];
	temp[(*j)++] = str[(*i)++];
	while (str[*i] != '\0' && str[*i] != c)
		temp[(*j)++] = str[(*i)++];
	if (str[*i] == '\0')
		return (1);
	temp[(*j)++] = str[(*i)++];
	return (0);
}

void	skip_space(char **temp, char **full_task, int i)
{
	while ((*temp)[i] != '\0' && ((*temp)[i] == ' ' || (*temp)[i] == '	'))
	{
		(*temp)++;
		(*full_task)++;
	}
}

int	*get_fd(void)
{
	static int	fd;

	return (&fd);
}
