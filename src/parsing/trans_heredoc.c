/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:32:37 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/15 04:48:23 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <readline/readline.h>

// 1 : > :redirige la sortie
// 2 : < :redirige l'entree
// 3 : >> :redirige la sortie et garde le contenu
// 4 : << :recupere avec readline

int	for_d_enter(t_task **token)
{
	char	*newcontent;
	char	*line;

	newcontent = NULL;
	while (1)
	{
		line = readline(">");
		if (line == 0)
			break ;
		if (ft_strcmp(line, &(*token)->content[2]) == 0)
			break ;
		stock(&newcontent, line);
		stock(&newcontent, "\n");
	}
	free((*token)->content);
	(*token)->type = 4;
	if (line == 0)
		return ((*token)->content = calloc(1, 1), 0);
	(*token)->content = newcontent;
	return (0);
}

int	trans_heredoc(t_task **token)
{
	char	*temp;

	if ((*token)->content[1] != '>' && (*token)->content[1] != '<')
	{
		if ((*token)->content[0] == '>')
			(*token)->type = 1;
		else
			(*token)->type = 2;
		temp = ft_substr((*token)->content, 1, ft_strlen((*token)->content));
		free((*token)->content);
		(*token)->content = temp;
		return (0);
	}
	if ((*token)->content[0] != (*token)->content[1])
		return (1);
	if ((*token)->content[1] == '<')
		return (for_d_enter(token));
	(*token)->type = 3;
	temp = ft_substr((*token)->content, 2, ft_strlen((*token)->content));
	free((*token)->content);
	(*token)->content = temp;
	return (0);
}
