/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:01:26 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/08 03:33:38 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// int	scan_trans(t_task **token, t_env_ex **env_ex)
// {
// 	int	i;
// 	int	j;
// 	char	*temp;

// 	i = 0;
// 	j = 0;
// 	if ((*token)->content[0] == '>' || (*token)->content[0] == '<')
// 		return (trans_heredoc(token, env_ex)); // a coder
// 	temp = malloc((ft_strlen((*token)->content) + 1)* sizeof(char));
// 	while ((*token)->content[i] != '\0')
// 	{
// 		if ((*token)->content[i] == '\'')
// 			if (trans_squote(token, env_ex, temp, &i, &j) == 1) // a coder
// 			return (free(temp), 1);
// 		if ((*token)->content[i] == '\"')
// 			if (trans_dquote(token, env_ex, temp, &i, &j) == 1) // a coder
// 			return (free(temp), 1);
// 		if ((*token)->content[i] == '$')
// 			if (trans_var(token, env_ex, temp, &i, &j) == 1) // a coder
// 			return (free(temp), 1);
// 		if ((*token)->content[i] != '\0')
// 			temp[j++] = (*token)->content[i++];
// 	}
// 	free((*token)->content);
// 	(*token)->content = ft_strdup(temp);
// 	return (free(temp), 0);
// }

// int	trans_token(t_command **first, t_env_ex **env_ex)
// {
// 	t_task	*task;

// 	task = (*first)->first;
// 	while (*first != NULL)
// 	{
// 		while (task != NULL)
// 		{
// 			scan_trans(&task, env_ex);
// 			task = task->next;
// 		}
// 		(*first) = (*first)->next;
// 		task = (*first)->first;
// 	}
// 	return (0);
// }