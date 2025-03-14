/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:22:31 by marvin            #+#    #+#             */
/*   Updated: 2025/03/14 18:15:12 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

t_task *check_first(t_command *command)
{
	t_task *task;

	task = command->first;
	while (task->type != 0 && task != NULL)
		task = task->next;
	return (task);
}
int	is_builtin(char	*content)
{
	int		i;

	i = ft_strlen(content);
	if (i != 0)
	{
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
	}
	return (1);
}

int	exec_builtin(t_command *command, t_env_ex *env)
{
	t_task	*task;
	int		i;
	int		ret;
	int		saved_stdout;

	
	ret = -1;
	task = check_first(command);
	i = ft_strlen(task->content);
	saved_stdout = ft_verif_out_put(command);
	if (i != 0)
	{
		if (!ft_strncmp("echo", task->content, i))
			ret = ft_exec_echo(command, task);
		if (!ft_strncmp("export", task->content, i))
			ret = ft_exec_export(command, &env->env, task);
		if (!ft_strncmp("unset", task->content, i))
			ret = ft_exec_unset(task, &env->env);
		if (!ft_strncmp("pwd", task->content, i))
			ret = ft_exec_pwd(env->env);
		if (!ft_strncmp("env", task->content, i))
			ret = ft_exec_env(command, env->env);
		if (!ft_strncmp("cd", task->content, i))
			ret = ft_exec_cd(task, &env->env);
		if (!ft_strncmp("exit", task->content, i))
			ret = 12;
	}
	ft_close_out_put(command, saved_stdout);
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
