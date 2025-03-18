/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:22:31 by marvin            #+#    #+#             */
/*   Updated: 2025/03/18 17:56:54 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

int	is_builtin(t_command *command)
{
	int		i;
	t_task	*task;

	task = first_task(command);
	if (task == NULL)
		return (1);
	i = ft_strlen(task->content);
	if (i != 0)
	{
		if (!ft_strncmp("echo", task->content, i))
			return (0);
		if (!ft_strncmp("export", task->content, i))
			return (0);
		if (!ft_strncmp("unset", task->content, i))
			return (0);
		if (!ft_strncmp("pwd", task->content, i))
			return (0);
		if (!ft_strncmp("env", task->content, i))
			return (0);
		if (!ft_strncmp("cd", task->content, i))
			return (0);
		if (!ft_strncmp("exit", task->content, i))
			return (0);
	}
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
	if (!ft_strncmp("echo", task->content, ft_strlen(task->content)))
		ret = ft_exec_echo(command, task);
	if (!ft_strncmp("export", task->content, ft_strlen(task->content)))
		ret = ft_exec_export(command, &env->env, task);
	if (!ft_strncmp("unset", task->content, ft_strlen(task->content)))
		ret = ft_exec_unset(task, &env->env);
	if (!ft_strncmp("pwd", task->content, ft_strlen(task->content)))
		ret = ft_exec_pwd(env->env);
	if (!ft_strncmp("env", task->content, ft_strlen(task->content)))
		ret = ft_exec_env(command, env->env);
	if (!ft_strncmp("cd", task->content, ft_strlen(task->content)))
		ret = ft_exec_cd(task, &env->env);
	if (!ft_strncmp("exit", task->content, ft_strlen(task->content)))
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
