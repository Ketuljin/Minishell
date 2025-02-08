/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:53:38 by vdunatte          #+#    #+#             */
/*   Updated: 2025/02/02 03:11:09 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing(char *line, char **envp, t_command **first, int value_return)
{
	int		i;
	char	*temp;

	i = 0;
	(void)envp;
	(void)value_return;
	temp = NULL;
	*first = lstnew(NULL);
	i = split_pipe(line, *first);
	free(line);
	if (i != 0)
		return (i);
	free(temp);
	return (i);
}
