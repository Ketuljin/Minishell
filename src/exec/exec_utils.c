/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:17:57 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/22 23:35:18 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

char	last_content(char *str)
{
	if (!str)
		return ('\0');
	return (str[ft_strlen(str) -1]);
}

t_task	*first_task(t_command *command)
{
	t_task	*actual_task;

	actual_task = command->first;
	while (actual_task)
	{
		if (actual_task->type == 0)
			return (actual_task);
		actual_task = actual_task->next;
	}
	return (NULL);
}

void	clean_all(char **args, t_env_ex *env_ex, t_command **command)
{
	if (args != NULL)
		free_double(args);
	ft_tabfree(env_ex->env);
	free(env_ex);
	free_struct(command);
	rl_clear_history();
}

int	check_sign(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	return (0);
}
