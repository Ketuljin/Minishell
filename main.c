/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:30:20 by vdunatte          #+#    #+#             */
/*   Updated: 2024/12/05 21:33:22 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newlibft/libft.h"
#include "structure_minishell.h"
# include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

void	free_struct2(t_task	*first)
{
	if (first == NULL)
		return ();
	free_struct2(first->next);
	free(first->content);
	first->content = NULL;
	first->prev = NULL;
	free(first);
	first = NULL;
}

void	free_struct(t_command	*first)
{
	if (first == NULL)
		return ();
	free_struct(first->next);
	free(first->full_task);
	first->full_task = NULL;
	free_struct2(first->first);
	free(first);
	first = NULL;
}

int	main(int argc, char const **argv, char **envp)
{
	char		**environment;
	t_command	*first;
	// char	*test;

	(void)argv;
	(void)argc;
	environment = ft_tabdup(envp);
	first = NULL;
	// test = readline("torture : ");
	ft_tabfree(environment);
	free_struct(first);
	return 0;
}