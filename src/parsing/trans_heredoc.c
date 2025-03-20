/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:32:37 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/20 04:32:52 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <readline/readline.h>

// 1 : > :redirige la sortie
// 2 : < :redirige l'entree
// 3 : >> :redirige la sortie et garde le contenu
// 4 : << :recupere avec readline

void	write_error_heredoc(char *eof)
{
	write(2, "torture: warning: here-document at line 42 delimited ", 54);
	write(2, "by end-of-file (wanted `", 25);
	write(2, eof, ft_strlen(eof));
	write(2, "')\n", 4);
}

void	take_herdoc2(char *eof)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		set_signals(S_HEREDOC);
		line = readline(">");
		set_signals(S_IGNORE);
		if (line == 0)
		{
			write_error_heredoc(eof);
			break ;
		}
		if (ft_strcmp(line, eof) == 0)
			break ;
		if (i++ != 0)
			write(g_last_sig, "\n", 1);
		write(g_last_sig, line, ft_strlen(line));
	}
}

void	take_herdoc(t_env_ex **env_ex, t_command *first, t_count *count)
{
	int		i;
	char	eof[1000000];

	ft_bzero(eof, 1000000);
	i = 0;
	while (first->first->content[i + 2] != '\0')
	{
		eof[i] = first->first->content[i + 2];
		i++;
	}
	free_all(env_ex, &first, &count);
	i = 0;
	g_last_sig = open("/tmp/tmp_minishell.txt", O_WRONLY | O_CREAT | O_APPEND,
			0644);
	if (g_last_sig == -1)
		exit(1);
	take_herdoc2(eof);
	close(g_last_sig);
	g_last_sig = 0;
	exit(0);
}

int	for_d_enter(t_task **token, t_env_ex **env_ex, t_command *first,
			t_count *count)
{
	pid_t	pid;
	int		i;
	char	*temp;

	pid = fork();
	if (pid == -1)
		return (1);
	(*token)->type = 4;
	if (pid == 0)
		take_herdoc(env_ex, first, count);
	else if (pid > 0)
	{
		waitpid(pid, &i, 0);
		if (i != 0)
		{
			if (i == 130)
				g_last_sig = 130;
			return (1);
		}
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
		printf("%s\n", (*token)->content);
		close(i);
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
		return (1);
	if ((*token)->content[1] == '<')
		return (for_d_enter(token, env_ex, first, count));
	(*token)->type = 3;
	temp = ft_substr((*token)->content, 2, ft_strlen((*token)->content));
	free((*token)->content);
	(*token)->content = temp;
	return (0);
}
