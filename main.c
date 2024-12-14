/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:30:20 by vdunatte          #+#    #+#             */
/*   Updated: 2024/12/14 03:03:33 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_task	*test2(void)
{
	t_task *first;

	first = malloc(sizeof(t_task)+1);
	first->next = NULL;
	first->prev = NULL;
	first->content = NULL;
	first->content = ft_strdup("0123456789\0");
	first->type = 12;
	return (first);
}

t_command	*test(void)
{
	t_command *first;

	first = malloc(sizeof(t_command)+1);
	first->next = NULL;
	first->first = test2();
	first->first->next= test2();
	first->first->next->next = test2();
	first->full_task = NULL;
	first->full_task = ft_strdup("0123456789\0");
	first->out_put = STDOUT_FILENO;
	first->in_put = STDIN_FILENO;
	return (first);
}

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