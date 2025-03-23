/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_heredoc_child.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:15:56 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/23 03:18:03 by vdunatte         ###   ########.fr       */
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
	int		fd;

	i = 0;
	fd = *get_fd();
	while (1)
	{
		set_signals(S_HEREDOC);
		line = readline("> ");
		set_signals(S_IGNORE);
		if (line == 0)
		{
			write_error_heredoc(eof);
			break ;
		}
		if (ft_strcmp(line, eof) == 0)
			break ;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

void	parse_eof(char *src, char *eof)
{
	char	c;
	int		i;
	int		j;

	c = '\0';
	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		if (!c && ft_strchr("\"\'", src[i]))
			c = src[i++];
		if (src[i] == c)
		{
			c = '\0';
			i++;
		}
		else if (src[i])
			eof[j++] = src[i++];
	}
}

#define EOF_MAXLEN 1000000

int	get_eof(char *eof, char *src)
{
	if (ft_strlen(src) >= EOF_MAXLEN)
	{
		write(STDERR_FILENO, "torture : eof too long\n", 24);
		return (22);
	}
	if (src[0] == '>' || src[0] == '<')
	{
		write(2, "torture : syntax error near unexpected token '", 47);
		write(STDERR_FILENO, src, 1);
		write(STDERR_FILENO, "'\n", 2);
		return (2);
	}
	parse_eof(src, eof);
	return (0);
}

void	take_herdoc(t_task **token, t_env_ex *env_ex, t_command *first,
			t_count *count)
{
	char	eof[EOF_MAXLEN];
	int		i;

	ft_bzero(eof, EOF_MAXLEN);
	i = get_eof(eof, (*token)->content + 2);
	if (i != 0)
	{
		free_all(env_ex, &first, &count);
		exit(i);
	}
	free_all(env_ex, &first, &count);
	*get_fd() = open("/tmp/tmp_minishell.txt", O_WRONLY | O_CREAT | O_APPEND,
		0644);
	if (*get_fd() == -1)
	{
		write(STDERR_FILENO, "torture : can't creat 'tmp_minishell'\n", 39);
		exit(9);
	}
	take_herdoc2(eof);
	close(*get_fd());
	exit(0);
}
