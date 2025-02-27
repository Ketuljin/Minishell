/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 00:23:23 by vdunatte          #+#    #+#             */
/*   Updated: 2025/02/27 18:39:37 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	skip_quote_index(char *str, int *i)
{
	return (0);
}

int	add_del_space(char *full_task, char **temp, int b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (full_task[i] != '\0')
	{
		if (skip_quote_index(full_task, &i) == 1)
			return (1);
		if(full_task[i] == '>' || full_task[i] == '<')
		{
			if(b-- != 1 && (full_task[i - 1] != ' ' || full_task[i - 1] != '	'))
				(*temp)[j++] = ' ';
			(*temp)[j++] = full_task[i++];
			if(full_task[i] != '\0' && full_task[i] == full_task[i - 1])
				(*temp)[j++] = full_task[i++];
			if(full_task[i] != '\0' && full_task[i] == full_task[i- 1])
				return (1);
			if(full_task[i] != '\0' && (full_task[i] == ' ' 
				|| full_task[i] == '	'))
				while (full_task[i] == ' ' || full_task[i] == '	')
					i++;
		}
		if (full_task[i] != '\0')
			(*temp)[j++] = full_task[i++];
	}
	return (0);
}

int	check_heredoc(char **full_task)
{
	int	i;
	char	*temp;
	i = char_count(*full_task, '<', '>');
	if (i == 0)
		return (0);
	temp = ft_calloc(ft_strlen(*full_task) + i + 1, sizeof(char));
	i = 0;
	if (*full_task[0] == '>' || *full_task[0] == '<')
		i = 1;
	if (add_del_space(*full_task, &temp, i) == 1)
		return(free(temp), 1);
	printf("%s\n", temp);
	free(*full_task);
	*full_task = ft_strdup(temp);
	free(temp);
	return (0);
}
