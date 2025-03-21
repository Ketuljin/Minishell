/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:32:37 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/21 04:59:59 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// 1 : > :redirige la sortie
// 2 : < :redirige l'entree
// 3 : >> :redirige la sortie et garde le contenu
// 4 : << :recupere avec readline

int	for_d_enter(t_task **token, t_env_ex **env_ex, t_command *first,
			t_count *count)
{
	pid_t	pid;
	int		i;
	char	*temp;

	(*token)->type = 4;
	pid = fork();
	if (pid == -1)
		return (print_error("torture : can't fork\n", env_ex, 10));
	if (pid == 0)
		take_herdoc(token, env_ex, first, count);
	else if (pid > 0)
	{
		waitpid(pid, &i, 0);
		if (i != 0)
			return (i);
		i = open("/tmp/tmp_minishell.txt", O_RDONLY, 0644);
		free((*token)->content);
		(*token)->content = NULL;
			temp = get_next_line(i);
		while (temp != NULL)
		{
			stock(&(*token)->content, temp);
			free(temp);
			temp = get_next_line(i);
		}
		close(i);
		unlink("/tmp/tmp_minishell.txt");
	}
	return (0);
}

int	trans_heredoc(t_task **token, t_env_ex **env_ex, t_command *first,
			t_count *count)
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
		return (print_error("syntax error near unexpected token\n", env_ex, 2));
	if ((*token)->content[1] == '<')
		return (for_d_enter(token, env_ex, first, count));
	(*token)->type = 3;
	temp = ft_substr((*token)->content, 2, ft_strlen((*token)->content));
	free((*token)->content);
	(*token)->content = temp;
	return (0);
}
