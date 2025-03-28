/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 00:23:23 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/20 20:25:52 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	add_del_space(char *f_task, char *temp, int b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (f_task[i] != '\0')
	{
		skip_quote_index(temp, f_task, &i, &j);
		if (f_task[i] == '>' || f_task[i] == '<')
		{
			if (b-- != 1 && (f_task[i - 1] != ' ' || f_task[i - 1] != '	'))
				temp[j++] = ' ';
			temp[j++] = f_task[i++];
			if (f_task[i] != '\0' && f_task[i] == f_task[i - 1])
				temp[j++] = f_task[i++];
			if (f_task[i] != '\0' && f_task[i] == f_task[i - 1])
				return (1);
			if (f_task[i] != '\0' && (f_task[i] == ' ' || f_task[i] == '	'))
				while (f_task[i] == ' ' || f_task[i] == '	')
					i++;
		}
		if (f_task[i] != '\0')
			temp[j++] = f_task[i++];
	}
	return (0);
}

int	norm_heredoc(char **full_task)
{
	int		i;
	char	*temp;

	i = char_count(*full_task, '<', '>');
	if (i == 0)
		return (0);
	temp = ft_calloc(ft_strlen(*full_task) + i + 1, sizeof(char));
	i = 0;
	if (*full_task[0] == '>' || *full_task[0] == '<')
		i = 1;
	if (add_del_space(*full_task, temp, i) == 1)
		return (free(temp), 1);
	free(*full_task);
	*full_task = ft_strdup(temp);
	free(temp);
	return (0);
}
