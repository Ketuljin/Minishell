/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:53:38 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/08 05:29:24 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
//faire pour $PWD avec getcwd

int	parsing(char *line, t_command **first, t_env_ex **env_ex)
{
	int		i;
	char	*temp;

	i = 0;
	(void)env_ex;
	temp = NULL;
	*first = lst_command_new(NULL);
	i = split_pipe(line, *first);
	if (i != 0)
		return (i);
	free(line);
	i = split_token(*first);
	if (i != 0)
		return (i);
	// i = trans_token(first, env_ex);
	// if (i != 0)
	// 	return (i);
	free(temp);
	return (i);
}
