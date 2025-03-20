/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:17:57 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/20 16:03:32 by jkerthe          ###   ########.fr       */
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

int	count_slash(char *content)
{
	int	i;
	int	cpt;

	cpt = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == '/')
		{
			cpt++;
			i++;
			while (content[i] == '/')
				i++;
		}
		else
		{
			cpt++;
			i++;
		}
	}
	return (cpt);
}


