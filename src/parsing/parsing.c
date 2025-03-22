/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:53:38 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/22 17:55:21 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	perror_spe(char c)
{
	if (c == '|' || c == '\0')
		write(2, "torture: syntax error near unexpected token `newline'\n", 55);
	else
	{
		write(2, "torture: syntax error near unexpected token `", 46);
		write(2, &c, 1);
		write(2, "'\n", 3);
	}
	return (1);
}

#define MSG_ERROR_PIPE "torture : syntax error near unexpected token `|'\n"

int	vrf_nonly_hrdcpipe(char *str, t_env_ex **env_ex, int i)
{
	while (str[0] != '\0' && (str[0] == ' ' || str[0] == '	'))
		str++;
	if (str[0] == '\0' && i == 0)
		return (1);
	if (str[0] == '|')
		return (print_err(MSG_ERROR_PIPE, env_ex, 2));
	while (str[0] != '\0')
	{
		if (skip_quote(&str) == 1)
			return (0);
		if (str[0] == '|')
			return (vrf_nonly_hrdcpipe(++str, env_ex, 1));
		if (str[0] == '>' || str[0] == '<')
		{
			if ((str++, 1) || str[0] == str[-1])
				str++;
			while (str[0] != '\0' && (str[0] == ' ' || str[0] == '	'))
				str++;
			if (ft_strchr("|><;\0", str[0]) != NULL)
				return (perror_spe(str[0]));
		}
		else if (str[0] != '\0')
			str++;
	}
	return (0);
}

int	parsing(char *line, t_command **first, t_env_ex **env_ex)
{
	int	i;

	if (line[0] == '\0')
		return (free(line), 1);
	if (vrf_nonly_hrdcpipe(line, env_ex, 0))
		return (free(line), 1);
	*first = lst_command_new(NULL);
	if (split_pipe(line, *first) != 0)
		return (print_err("torture : syntax error\n", env_ex, 22));
	free(line);
	if (split_token(*first, env_ex) != 0)
		return (1);
	i = trans_token(*first, env_ex);
	if (i != 0)
	{
		if (g_last_sig == 130)
			return (1);
		return (1);
	}
	if ((*first)->first->next == NULL && (*first)->next == NULL
		&& (*first)->first->content[0] == '\0' && (*first)->first->type == 0)
		return (print_err("Command '' not found\n", env_ex, 127));
	return (0);
}
