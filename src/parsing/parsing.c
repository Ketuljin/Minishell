/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:53:38 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/16 02:35:36 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing(char *line, t_command **first, t_env_ex **env_ex)
{
	if (line[0] == '\0')
		return (free(line), 1);
	*first = lst_command_new(NULL);
	if (split_pipe(line, *first) != 0)
		return (print_error("syntax error\n", env_ex, 22));
	free(line);
	if (split_token(*first, env_ex) != 0)
		return (1);
	if (trans_token(*first, env_ex) != 0)
		return (print_error("syntax error near unexpected token\n", env_ex, 2));
	return (0);
}
