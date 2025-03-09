/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:32:37 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/09 05:38:56 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// 1 : >
// 2 : <
// 3 : >>
// 4 : <<

int	for_d_enter(t_task **token, t_env_ex **env_ex)
{
	printf("lalalala\n");
	(void)env_ex;
	(void)token;
	return(0);
}

int	trans_heredoc(t_task **token, t_env_ex **env_ex)
{
	char *temp;

	if ((*token)->content[1] != '>' && (*token)->content[1] != '<')
	{
		if((*token)->content[0] == '>')
			(*token)->type = 1;
		else
			(*token)->type = 2;
		temp = ft_substr((*token)->content, 1, ft_strlen((*token)->content));
		free((*token)->content);
		(*token)->content = temp;
		return (0);
	}
	if((*token)->content[0] != (*token)->content[1])
		return (1);
	if ((*token)->content[1] != '<')
		return (for_d_enter(token, env_ex));
	(*token)->type = 3;
	temp = ft_substr((*token)->content, 2, ft_strlen((*token)->content));
	free((*token)->content);
	(*token)->content = temp;
	return (0);
}