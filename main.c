/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:30:20 by vdunatte          #+#    #+#             */
/*   Updated: 2024/12/14 04:08:23 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char const **argv, char **envp)
{
	char		**environment;
	t_command	*first;
	char		*line;

	(void)argv;
	(void)argc;
	environment = ft_tabdup(envp);
	while (1)
	{
		line = readline("torture : ");
		parsing(line, environment, first);
		free_struct(first);
		free(line);
	}
	ft_tabfree(environment);
	free_struct(first);
	
	return (0);
}
