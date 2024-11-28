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
