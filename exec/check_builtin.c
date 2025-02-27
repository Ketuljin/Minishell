/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:22:31 by marvin            #+#    #+#             */
/*   Updated: 2025/02/27 19:51:19 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

int	is_builtin(char *content)
{
	int	i;

	i = ft_strlen(content);
	if (!ft_strncmp("echo", content, i))
		return (0);
	if (!ft_strncmp("export", content, i))
		return (0);
	if (!ft_strncmp("unset", content, i))
		return (0);
	if (!ft_strncmp("pwd", content, i))
		return (0);
	if (!ft_strncmp("env", content, i))
		return (0);
	if (!ft_strncmp("cd", content, i))
		return (0);
	if (!ft_strncmp("exit", content, i))
		return (0);
	return (1);
}

int	exec_builtin(t_command *command, char ***env)
{
	t_task	*task;
	int		i;
	int		ret;

	ret = -1;
	task = command->first;
	i = ft_strlen(command->first->content);
	if (!ft_strncmp("echo", task->content, i))
		ret = ft_exec_echo(command);
	if (!ft_strncmp("export", task->content, i))
		ret = ft_exec_export(command, env);
	if (!ft_strncmp("unset", task->content, i))
		ret = ft_exec_unset(command, env);
	if (!ft_strncmp("pwd", task->content, i))
		ret = ft_exec_pwd(command);
	if (!ft_strncmp("env", task->content, i))
		ret = ft_exec_env(command, *env);
	if (!ft_strncmp("cd", task->content, i))
		ret = ft_exec_cd(command, env);
	return (ret);
}

t_command	*search_command(t_command *command, int count)
{
	while (command != NULL)
	{
		if (count == 0)
			return (command);
		count--;
		command = command->next;
	}
	return (NULL);
}
