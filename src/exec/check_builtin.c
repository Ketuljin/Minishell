/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:22:31 by marvin            #+#    #+#             */
/*   Updated: 2025/03/23 18:53:05 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

int	is_builtin(t_command *command)
{
	t_task	*task;
	char	*content;

	task = first_task(command);
	if (task == NULL)
		return (1);
	content = task->content;
	if (!ft_strncmp("echo", content, size_comp("echo", content)))
		return (0);
	if (!ft_strncmp("export", content, size_comp("export", content)))
		return (0);
	if (!ft_strncmp("unset", content, size_comp("unset", content)))
		return (0);
	if (!ft_strncmp("pwd", content, size_comp("pwd", content)))
		return (0);
	if (!ft_strncmp("env", content, size_comp("env", content)))
		return (0);
	if (!ft_strncmp("cd", content, size_comp("cd", content)))
		return (0);
	if (!ft_strncmp("exit", content, size_comp("exit", content)))
		return (0);
	return (1);
}

static int	ft_exec_builtin(t_command *command, t_env_ex *env,
						t_command *first_command, int saved_stdout)
{
	int		ret;
	char	*content;

	content = first_task(command)->content;
	ret = -1;
	if (!ft_strncmp("echo", content, size_comp("echo", content)))
		ret = ft_exec_echo(command, first_task(command));
	if (!ft_strncmp("export", content, size_comp("export", content)))
		ret = ft_exec_export(command, &env->env, first_task(command));
	if (!ft_strncmp("unset", content, size_comp("unset", content)))
		ret = ft_exec_unset(first_task(command), &env->env);
	if (!ft_strncmp("pwd", content, size_comp("pwd", content)))
		ret = ft_exec_pwd(env->env);
	if (!ft_strncmp("env", content, size_comp("env", content)))
		ret = ft_exec_env(command, env->env);
	if (!ft_strncmp("cd", content, size_comp("cd", content)))
		ret = ft_exec_cd(first_task(command), &env->env);
	if (!ft_strncmp("exit", content, size_comp("exit", content)))
		ft_exec_exit (command, env, first_command, saved_stdout);
	return (ret);
}

int	exec_builtin(t_command *command, t_env_ex *env, t_command *first_command)
{
	t_task	*task;
	int		saved_stdout;
	int		ret;

	task = first_task(command);
	saved_stdout = dup(STDOUT_FILENO);
	if (!handle_redir(command, false, true))
		ret = 1;
	else
	{
		if (command->fd_in_put < 0)
			command->fd_in_put = STDIN_FILENO;
		if (command->fd_out_put < 0)
			command->fd_out_put = STDOUT_FILENO;
		ret = ft_exec_builtin(command, env, first_command, saved_stdout);
	}
	if (dup2(saved_stdout, STDOUT_FILENO) == -1)
		perror("exec_builtin: couldn't restore stdout");
	ft_close(&saved_stdout);
	command->fd_out_put = STDOUT_FILENO;
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
