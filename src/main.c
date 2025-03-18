/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:30:20 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/18 02:07:17 by vdunatte         ###   ########.fr       */
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
	set_signals(S_IGNORE);
	env_ex = malloc(sizeof(t_env_ex));
	env_ex->env = ft_tabdup(envp);
	first = NULL;
	test = 0;
	env_ex->exit_code = 0;
	while (test != 10)
	{
		set_signals(S_INTERACTIVE);
		line = readline("torture : ");
		set_signals(S_IGNORE);
		if (line == NULL)
			break ;
		add_history(line);
		if (parsing(line, &first, &env_ex) == 0)
		{
			printf("fait l'exec\n");
			// ft_execute(first, env_ex);
		}
		else
			printf("fait pas l'exec\n");
		free_struct(&first);
		test++;
	}
	ft_tabfree(env_ex->env);
	free(env_ex);
	free_struct(&first);
	rl_clear_history();
	return (0);
}
