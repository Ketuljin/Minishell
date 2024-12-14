/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:30:20 by vdunatte          #+#    #+#             */
/*   Updated: 2024/12/14 03:29:32 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char const **argv, char **envp)
{
	char		**environment;
	t_command	*first;

	(void)argv;
	(void)argc;
	environment = ft_tabdup(envp);
	first = test();
	first->next = test();
	first->next->next = test();
	ft_tabfree(environment);
	free_struct(first);
	return (0);
}

// test = readline("torture : ");