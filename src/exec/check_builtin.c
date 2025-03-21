/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:22:31 by marvin            #+#    #+#             */
/*   Updated: 2025/03/21 16:37:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

int	is_builtin(t_command *command)
{
	t_task	*task;

	task = first_task(command);
	if (task == NULL)
		return (1);
	if (!ft_strncmp("echo", task->content, size_compare("echo", task->content)))
		return (0);
	if (!ft_strncmp("export", task->content, size_compare("export", task->content)))
		return (0);
	if (!ft_strncmp("unset", task->content, size_compare("unset", task->content)))
		return (0);
	if (!ft_strncmp("pwd", task->content, size_compare("pwd", task->content)))
		return (0);
	if (!ft_strncmp("env", task->content, size_compare("env", task->content)))
		return (0);
	if (!ft_strncmp("cd", task->content, size_compare("cd", task->content)))
		return (0);
	if (!ft_strncmp("exit", task->content, size_compare("exit", task->content)))
		return (0);
	return (1);
}

int	ft_exec_builtin(t_command *command, t_env_ex *env,
						t_command *first_command, t_task *task)
{
	int	ret;
	int	saved_stdout;

	saved_stdout = dup(STDOUT_FILENO);
	ft_verif_out_put(command);
	ret = -1;
	if (!ft_strncmp("echo", task->content, size_compare("echo", task->content)))
		ret = ft_exec_echo(command, task);
	if (!ft_strncmp("export", task->content, size_compare("export", task->content)))
		ret = ft_exec_export(command, &env->env, task);
	if (!ft_strncmp("unset", task->content, size_compare("unset", task->content)))
		ret = ft_exec_unset(task, &env->env);
	if (!ft_strncmp("pwd", task->content, size_compare("pwd", task->content)))
		ret = ft_exec_pwd(env->env);
	if (!ft_strncmp("env", task->content, size_compare("env", task->content)))
		ret = ft_exec_env(command, env->env);
	if (!ft_strncmp("cd", task->content, size_compare("cd", task->content)))
		ret = ft_exec_cd(task, &env->env);
	if (!ft_strncmp("exit", task->content, size_compare("exit", task->content)))
		ft_exec_exit (command, env, first_command, saved_stdout);
	ft_close_out_put(command, saved_stdout);
	return (ret);
}

int	exec_builtin(t_command *command, t_env_ex *env, t_command *first_command)
{
	t_task	*task;
	int		ret;

	task = first_task(command);
	ret = ft_exec_builtin(command, env, first_command, task);
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
