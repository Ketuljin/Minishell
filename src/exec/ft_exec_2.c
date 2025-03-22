/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:37:39 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/22 21:52:58 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

char	**create_args(t_task *task)
{
	char	**args;
	int		i;

	i = 1;
	if (task == NULL)
		return (NULL);
	args = malloc(sizeof(char *) * (count_task(task) + 1));
	args[0] = ft_strdup(task->content);
	task = task->next;
	while (task != NULL)
	{
		if (task->type == 0)
		{
			args[i] = ft_strdup(task->content);
			i++;
		}
		task = task->next;
	}
	args[i] = NULL;
	return (args);
}

static void	print_exec_err(int type, char **args, int errsv)
{
	if (type == 0)
	{
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
	}
	else if (type == 1)
	{
		ft_putstr_fd("torture: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd(" : Is a directory\n", STDERR_FILENO);
	}
	else if (type == 2)
	{
		ft_putstr_fd("torture: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errsv), STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
}

static int	_try_execve_path(char **args, t_env_ex *env_ex, int *errsv)
{
	char		**paths;
	int			i;
	char		*command;
	struct stat	buf;

	paths = ft_split(get_env_var("PATH", env_ex->env), ':');
	if (paths == NULL)
		return (false);
	i = -1;
	while (paths[++i])
	{
		command = ft_strjoinv(3, paths[i], "/", args[0]);
		if (command == NULL)
			return (ft_tabfree(paths), false);
		if (stat(command, &buf) == 0 && !S_ISDIR(buf.st_mode))
		{
			set_signals(S_DEFAULT);
			execve(command, args, env_ex->env);
			*errsv = errno;
			set_signals(S_IGNORE);
		}
		free(command);
	}
	return (ft_tabfree(paths), true);
}

int	try_execve(t_command *command, t_env_ex *env_ex)
{
	char		**args;
	int			errsv;
	struct stat	buf;

	if (!first_task(command))
		return (-1);
	args = create_args(first_task(command));
	ft_verif_out_put(command);
	ft_verif_in_put(command);
	errsv = ENOENT;
	if (ft_strchr(args[0], '/') || get_env_var("PATH", env_ex->env) == NULL)
	{
		set_signals(S_DEFAULT);
		execve(args[0], args, env_ex->env);
		errsv = errno;
		set_signals(S_IGNORE);
		if (stat(args[0], &buf) == 0 && S_ISDIR(buf.st_mode))
			return (print_exec_err(1, args, errsv), ft_tabfree(args), 126);
	}
	else
		if (!_try_execve_path(args, env_ex, &errsv))
			return (ft_tabfree(args), -1);
	if (errsv == ENOENT)
		return (print_exec_err(0, args, errsv), ft_tabfree(args), 127);
	return (print_exec_err(2, args, errsv), ft_tabfree(args), 126);
}
