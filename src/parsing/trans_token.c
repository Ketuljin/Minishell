/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:01:26 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/19 18:47:53 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	trans_squote(t_task **token, char *temp, t_count **count)
{
	(*count)->i++;
	while ((*token)->content[(*count)->i] != '\'')
	{
		temp[(*count)->j++] = (*token)->content[(*count)->i++];
	}
	(*count)->i++;
	return (0);
}

int	trans_dquote(t_task **token, t_env_ex **env_ex, char **tmp, t_count **count)
{
	(*count)->i++;
	while ((*token)->content[(*count)->i] != '\"')
	{
		if ((*token)->content[(*count)->i] == '$')
		{
			if ((*token)->content[(*count)->i + 1] == '\"')
				(*tmp)[(*count)->j++] = (*token)->content[(*count)->i++];
			else
				trans_var(token, env_ex, tmp, count);
		}
		else
		{
			(*tmp)[(*count)->j++] = (*token)->content[(*count)->i++];
		}
	}
	(*count)->i++;
	return (0);
} 

int	scan_trans(t_task **token, t_env_ex **env_ex)
{
	char	*temp;
	t_count	*count;

	count = malloc(sizeof(t_count) + 1);
	count->i = 0;
	count->j = 0;
	(void)env_ex;
	if ((*token)->content[0] == '>' || (*token)->content[0] == '<')
		if (trans_heredoc(token) != 0)
			return (1);
	temp = calloc((ft_strlen((*token)->content) + 1), sizeof(char));
	while ((*token)->content && (*token)->content[count->i] != '\0')
	{
		if ((*token)->content[count->i] == '\'')
			trans_squote(token, temp, &count);
		else if ((*token)->content[count->i] == '\"')
			trans_dquote(token, env_ex, &temp, &count);
		else if ((*token)->content[count->i] == '$')
			trans_var(token, env_ex, &temp, &count);
		else if ((*token)->content[count->i] != '\0' )
			temp[count->j++] = (*token)->content[count->i++];
	}
	free((*token)->content);
	(*token)->content = temp;
	return (free(count), 0);
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
				return (1);
			task = task->next;
		}
		first = first->next;
	}
	return (0);
}
