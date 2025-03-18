/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:53:14 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/18 02:07:30 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>

#include "minishell.h"
# include "../newlibft/libft.h"
# include "structure_minishell.h"

typedef struct s_count
{
	int	i;
	int	j;
}			t_count;

int			parsing(char *line, t_command **first, t_env_ex **env_ex);

int			split_pipe(char *line, t_command *first);
int			norm_heredoc(char **full_task);
int			split_token(t_command *first, t_env_ex **env_ex);
int			trans_token(t_command *first, t_env_ex **env_ex);

int			trans_heredoc(t_task **token);
int			trans_var(t_task **token, t_env_ex **env_ex, char **newcnt,
				t_count **count);

t_command	*lst_command_new(void *content);
char		*extract_skip(char **line, int len);
int			skip_quote(char **temp);
int			char_count(char *s, char c, char d);
int			print_error(char *msg_error, t_env_ex **env_ex, int exit_code);

#endif
