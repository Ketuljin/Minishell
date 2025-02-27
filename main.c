/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:30:20 by vdunatte          #+#    #+#             */
/*   Updated: 2025/02/27 18:07:12 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char const **argv, char **envp)
{
	char		**environment;
	t_command	*first;
	char		*line;
	int			test;
	int			value_return;

	(void)argv;
	(void)argc;
	environment = ft_tabdup(envp);
	first = NULL;
	test = 0;
	value_return = 0;
	while (test != 5)
	{
		line = readline("torture : ");
		add_history(line);
		parsing(line, environment, &first, value_return);
		free_struct(&first);
		test++;
	}
	ft_tabfree(environment);
	free_struct(&first);
	rl_clear_history();
	return (0);
}
