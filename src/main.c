/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:30:20 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/22 17:44:26 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(t_command **first, t_env_ex **env_ex)
{
	char	*line;

	while (1)
	{
		set_signals(S_INTERACTIVE);
		line = readline("torture : ");
		set_signals(S_IGNORE);
		if (g_last_sig == 130)
			(*env_ex)->exit_code = 130;
		g_last_sig = 0;
		if (line == NULL)
			return ;
		add_history(line);
		if (parsing(line, first, env_ex) == 0)
			ft_execute(*first, *env_ex);
		free_struct(first);
	}
}

int	main(int argc, char const **argv, char **envp)
{
	t_env_ex	*env_ex;
	t_command	*first;
	int			exit_code;

	(void)argv;
	(void)argc;
	rl_outstream = stderr;
	set_signals(S_IGNORE);
	env_ex = malloc(sizeof(t_env_ex));
	env_ex->env = ft_tabdup(envp);
	first = NULL;
	env_ex->exit_code = 0;
	minishell(&first, &env_ex);
	exit_code = env_ex->exit_code;
	ft_tabfree(env_ex->env);
	free(env_ex);
	free_struct(&first);
	rl_clear_history();
	return (exit_code);
}
