/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 03:42:49 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/16 02:35:57 by vdunatte         ###   ########.fr       */
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
	lst->fd_in_put = STDIN_FILENO;
	lst->fd_out_put = STDOUT_FILENO;
	return (lst);
}

int	split_pipe(char *line, t_command *first)
{
	int		i;
	char	*temp;

	i = 0;
	temp = line;
	while (temp[0] != '\0')
	{
		if (skip_quote(&temp) == 1)
			return (1);
		if (temp[0] == '|')
		{
			i = (long)temp - (long)line;
			first->full_task = extract_skip(&line, i);
			if (first->full_task == NULL)
				return (1);
			ft_lstadd_back((t_list **)&first, (t_list *)lst_command_new(NULL));
			first = first->next;
			temp = ++line;
		}
		if (temp[0] != '\0')
			temp++;
	}
	first->full_task = ft_strdup(line);
	return (first->full_task == NULL);
}
