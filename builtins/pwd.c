/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:49:19 by jkerthe           #+#    #+#             */
/*   Updated: 2024/11/28 15:49:19 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_builtins.h"

void	ft_exec_pwd(t_command *command, char	**env)
{
	char	*path;
	t_task	*task;

	task = command->first;
	if (task->next != NULL)
		return ;
	path = get_env_var("PWD", env);
	if(path == NULL)
	{
		ft_putstr_fd("Minishell: missing PWD", 1);
		return ;
	}
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	if (path)
	{
		free (path);
		path = NULL;
	}
	return ;
}
