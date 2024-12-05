/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_task.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:49:46 by jkerthe           #+#    #+#             */
/*   Updated: 2024/11/28 15:49:46 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_minishell.h"

int	count_task(t_command *command)
{
	t_task	*actual_task;
	int		i;

	i = 0;
	actual_task = command->task;
	while (actual_task->next)
	{
		i++;
		actual_task = actual_task->next;
	}
	return (i);
}
void	printf_export(char **stock)
{
	int	i;

	i = 0;
	while(stock[i])
	{
		ft_putstr_fd("declare -x ", command->out_put);
		ft_putstr_fd(stock[i], command->out_put);
		ft_putstr_fd("\n", command->out_put);
		i++;
	}
}