/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:30:20 by vdunatte          #+#    #+#             */
/*   Updated: 2024/12/19 03:35:08 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char const **argv, char **envp)
{
	char		**environment;
	t_command	*first;
	char		*line;
	int			test;

	(void)argv;
	(void)argc;
	environment = ft_tabdup(envp);
	first = NULL;
	test = 0;
	while (test != 2)
	{
		line = readline("torture : ");
		parsing(line, environment, first);
		free_struct(first);
		free(line);
		test++;
	}
	ft_tabfree(environment);
	free_struct(first);
	return (0);
}
