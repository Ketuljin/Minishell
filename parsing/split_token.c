/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:56:44 by vdunatte          #+#    #+#             */
/*   Updated: 2025/02/26 03:09:59 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_task	*lst_task_new(void *content)
{
	t_task	*lst;

	lst = malloc(sizeof(t_task));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	lst->type = 0;
	return (lst);
}

void	skip_space(char **temp, char **full_task, int i)
{
	while ((*temp)[i] != '\0' && ((*temp)[i] == ' ' || (*temp)[i] == '	'))
	{
		(*temp)++;
		(*full_task)++;
	}
}

int	splitter(char *full_task, t_task *first)
{
	int		i;
	char	*temp;

	i = 0;
	skip_space((temp = full_task, &temp), &full_task, 0);
	while (temp[0] != '\0')
	{
		if (skip_quote(&temp) == 1)
			return (1);
		if (temp[0] == ' ' || temp[0] == '	')
		{
			i = (long)temp - (long)full_task;
			first->content = extract_skip(&full_task, i);
			if (first->content == NULL)
				return (1);
			skip_space(&temp, &full_task, 1);
			ft_lstadd_back((t_list **)&first, (t_list *)lst_task_new(NULL));
			first = first->next;
			temp = ++full_task;
		}
		if (temp[0] != '\0')
			temp++;
	}
	first->content = ft_strdup(full_task);
	return (first->content == NULL);
}

int	split_token(t_command *first)
{
	if (first == NULL)
		return (0);
	if (check_heredoc(&(first->full_task)) == 0)
		return (1);
	first->first = lst_task_new(NULL);
	if (splitter(first->full_task, first->first) == 1)
		return (1);
	if (first->first->content[0] == '\0')
		return (1);
	return (split_token(first->next));
}
