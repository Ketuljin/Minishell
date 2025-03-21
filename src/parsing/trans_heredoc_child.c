/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_heredoc_child.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:15:56 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/21 04:34:58 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
		free(line);
	}
}

int	get_eof(char *eof, char *src)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	if (ft_strlen(src) > 1000000)
	{
		write(STDERR_FILENO, "torture : eof too long\n", 24);
		return(22);
	}
	if (src[i] == '>' || src[i] == '<')
	{
		write(2, "torture : syntax error near unexpected token '", 47);
		write(STDERR_FILENO, &src[i], 1);
		write(STDERR_FILENO, "'\n", 2);
		return (2);
	}
	while (src[i] != '\0')
	{
		skip_quote_index(eof, src, &i, &j);
		eof[j] = src[i];
		i++;
	}
	return (0);
}

void	take_herdoc(t_task **token, t_env_ex **env_ex, t_command *first,
			t_count *count)
{
	char	eof[1000000];
	int		i;

	ft_bzero(eof, 1000000);

	i = get_eof(eof, (*token)->content);
	if (i != 0)
	{
		free_all(env_ex, &first, &count);
		exit(i);
	}
	free_all(env_ex, &first, &count);
	g_last_sig = open("/tmp/tmp_minishell.txt", O_WRONLY | O_CREAT | O_APPEND,
			0644);
	if (g_last_sig == -1)
	{
		write(STDERR_FILENO, "torture : can't creat 'tmp_minishell'\n", 39);
		exit(9);
	}
	take_herdoc2(eof);
	close(g_last_sig);
	g_last_sig = 0;
	exit(0);
}