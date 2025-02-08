/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 03:42:49 by vdunatte          #+#    #+#             */
/*   Updated: 2025/02/08 01:30:21 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_command	*lst_command_new(void *content)
{
	t_command	*lst;

	lst = malloc(sizeof(t_command));
	if (lst == NULL)
		return (NULL);
	lst->full_task = content;
	lst->next = NULL;
	lst->first = NULL;
	lst->out_put = STDOUT_FILENO;
	lst->in_put = STDIN_FILENO;
	return (lst);
}

char	*extract_skip(char **line, int len)
{
	char	*ret;

	ret = ft_substr(*line, 0, len);
	if (ret == NULL)
		return (NULL);
	*line += len;
	return (ret);
}

int	split_pipe(char *line, t_command *first)
{
	int		i;
	char	*temp;

	i = 0;
	temp = line;
	while (temp[0] != '\0')
	{
		if (temp[0] == '\"' || temp[0] == '\'')
		{
			temp = ft_strchr(temp + 1, temp[0]);
			if (temp == NULL)
				return (1);
		}
		if (temp[0] == '|')
		{
			i = (long)temp - (long)line;
			first->full_task = extract_skip(&line, i);
			if (first->full_task == NULL)
				return (1);
			ft_lstadd_back((t_list **)&first, (t_list *)lst_command_new(NULL));
			first = first->next;
			line++;
			temp = line;
		}
		if (temp[0] != '\0')
			temp++;
	}
	first->full_task = ft_strdup(line);
	if (first->full_task == NULL)
		return (1);
	return (0);
}
