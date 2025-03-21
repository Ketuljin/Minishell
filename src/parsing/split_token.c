/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:56:44 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/21 20:18:35 by vdunatte         ###   ########.fr       */
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
	while (1)
	{
		if (skip_quote(&temp) == 1)
			return (1);
		if (temp[0] == ' ' || temp[0] == '	' || temp[0] == '\0')
		{
			i = (long)temp - (long)full_task;
			first->content = extract_skip(&full_task, i);
			if (first->content == NULL)
				return (1);
			skip_space(&temp, &full_task, 0);
			if (temp[0] == '\0')
				break ;
			ft_lstadd_back((t_list **)&first, (t_list *)lst_task_new(NULL));
			first = first->next;
		}
		else if (temp[0] != '\0')
			temp++;
	}
	return (first->content == NULL);
}

int	split_token(t_command *first, t_env_ex **env_ex)
{
	if (first == NULL)
		return (0);
	first->first = lst_task_new(NULL);
	if (norm_heredoc(&(first->full_task)) == 1)
		return (print_error("torture : syntax error near unexpected token\n",
				env_ex, 2));
	if (splitter(first->full_task, first->first) == 1)
		return (print_error("torture : syntax error\n", env_ex, 22));
	if (first->first->content[0] == '\0')
		return (print_error("torture : syntax error\n", env_ex, 22));
	return (split_token(first->next, env_ex));
}
