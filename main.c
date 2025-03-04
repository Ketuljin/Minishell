/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:30:20 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/04 03:53:53 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char const **argv, char **envp)
{
	t_env_ex	*env_ex;
	t_command	*first;
	char		*line;
	int			test;

	(void)argv;
	(void)argc;
	env_ex = malloc(sizeof(t_env_ex));
	env_ex->env = ft_tabdup(envp);
	first = NULL;
	test = 0;
	env_ex->exit_code = 0;
	while (test != 10)
	{
		line = readline("torture : ");
		add_history(line);
		parsing(line, &first, env_ex);
		// ft_execute(first, &env_ex);
		free_struct(&first);
		test++;
	}
	ft_tabfree(env_ex->env);
	free(env_ex);
	free_struct(&first);
	rl_clear_history();
	return (0);
}
