/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:43:55 by jkerthe           #+#    #+#             */
/*   Updated: 2024/11/28 15:43:55 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_builtins.h"

int	option_echo(char *a)
{
	if (*a != '-')
		return (1);
	a++;
	if (!*a)
		return (1);
	while (*a)
	{
		if (*a != 'n')
			return (1);
		a++;
	}
	return (0);
}

void	ft_exec_echo(t_command *command)
{
	t_task	*task;
	int		suppress_newline;
	int		first_arg;

	task = command->first->next;
	suppress_newline = 0;
	first_arg = 1;
	if (task && !option_echo(task->content))
	{
		suppress_newline = 1;
		task = task->next;
	}
	while (task)
	{
		if (!first_arg)
			ft_putstr_fd(" ", command->out_put);
		ft_putstr_fd(task->content, command->out_put);
		first_arg = 0;
		task = task->next;
	}
	if (!suppress_newline)
		ft_putstr_fd("\n", command->out_put);
	return ;
}



