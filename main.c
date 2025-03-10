/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:30:20 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/10 11:52:38 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char const **argv, char **envp)
{
	t_env_ex	*env_ex;
	t_command	*first;
	char		*line;
	int			test;
	int			tortue;

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
		tortue = parsing(line, &first, &env_ex);
		if (tortue == 0)
		{
			printf("fait l'exec\n");
			ft_execute(first, env_ex);
		}
		else
			printf("fait pas l'exec %d\n", tortue);
		free_struct(&first);
		test++;
	}
	ft_tabfree(env_ex->env);
	free(env_ex);
	free_struct(&first);
	rl_clear_history();
	return (0);
}
