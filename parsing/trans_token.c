/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:01:26 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/12 02:48:42 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	trans_squote(t_task **token, t_env_ex **env_ex, char *temp, int *i, int *j)
{
	(*i)++;
	(void)env_ex;
	while ((*token)->content[*i] != '\'')
	{
		temp[(*j)++] = (*token)->content[(*i)++];
	}
	(*i)++;
	return(0);
}

int	trans_dquote(t_task **token, t_env_ex **env_ex, char *temp, int *i, int *j)
{
	(*i)++;
	(void)env_ex;
	while ((*token)->content[*i] != '\"')
	{
		temp[(*j)++] = (*token)->content[(*i)++];
	}
	(*i)++;
	return(0);
}

int	scan_trans(t_task **token, t_env_ex **env_ex)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	(void)env_ex;
	if ((*token)->content[0] == '>' || (*token)->content[0] == '<')
		if (trans_heredoc(token) != 0)
			return (1);
	temp = calloc((ft_strlen((*token)->content) + 1), sizeof(char));
	while ((*token)->content[i] != '\0')
	{
		if ((*token)->content[i] == '\'')
			if (trans_squote(token, env_ex, temp, &i, &j) == 1) // a coder
			return (free(temp), 1);
		if ((*token)->content[i] == '\"')
			if (trans_dquote(token, env_ex, temp, &i, &j) == 1) // a coder
			return (free(temp), 1);
	// 	if ((*token)->content[i] == '$')
	// 		if (trans_var(token, env_ex, temp, &i, &j) == 1) // a coder
	// 		return (free(temp), 1);
		if ((*token)->content[i] != '\0')
			temp[j++] = (*token)->content[i++];
	}
	free((*token)->content);
	(*token)->content = temp;
	return ( 0);
}

int	trans_token(t_command *first, t_env_ex **env_ex)
{
	t_task	*task;

	while (first != NULL)
	{
		task = first->first;
		while (task != NULL)
		{
			if (scan_trans(&task, env_ex) == 1)
				return(5);
			printf("%s %d\n", task->content, task->type);
			task = task->next;
		}
		first = first->next;
	}
	return (0);
}
