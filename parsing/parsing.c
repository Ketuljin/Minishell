/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:53:38 by vdunatte          #+#    #+#             */
/*   Updated: 2025/01/26 00:50:56 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing(char *line, char **envp, t_command **first, int value_return)
{
	int		i;
	char	*temp;

	i = 0;
	(void)line;
	(void)envp;
	(void)value_return;
	temp = NULL;
	*first = lstnew(NULL);
	split_pipe(line, *first);
	free(line);
	printf("%s\n", (*first)->full_task);
	if ((*first)->next != NULL && (*first)->next->full_task != NULL)
		printf("%s\n", (*first)->next->full_task);
	free(temp);
	return (i);
}
