/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:53:38 by vdunatte          #+#    #+#             */
/*   Updated: 2025/01/08 02:53:00 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing(char *line, char **envp, t_command *first, int value_return)
{
	int		i;
	char	*temp;

	i = 0;
	(void)line;
	(void)envp;
	(void)first;
	temp = replace_var(line, envp, value_return);
	if (temp != NULL)
		printf("%s\n", temp);
	else
		printf("NULL");
	free(temp);
	return (i);
}
