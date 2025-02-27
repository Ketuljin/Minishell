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

#include "../structure_execute.h"

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

int	ft_exec_echo(t_command *command)
{
	t_task	*task;
	int		suppress_newline;

	task = command->first->next;
	suppress_newline = 0;
	if (task && !option_echo(task->content))
	{
		suppress_newline = 1;
		task = task->next;
	}
	while (task)
	{
		if (task->type == 0)
			ft_putstr_fd(task->content, command->fd_out_put);
		task = task->next;
	}
	if (!suppress_newline)
		ft_putstr_fd("\n", command->fd_out_put);
	return (0);
}
