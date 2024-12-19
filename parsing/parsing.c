/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:53:38 by vdunatte          #+#    #+#             */
/*   Updated: 2024/12/19 03:35:41 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing(char *line, char **envp, t_command *first)
{
	int	i;
	char	*temp;

	i = 0;
	(void)line;
	(void)envp;
	(void)first;
	temp = replace_var(line, envp);
	printf("%s\n", temp);
	free(temp);
	return (i);
}