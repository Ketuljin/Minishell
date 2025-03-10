/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:04:13 by jkerthe           #+#    #+#             */
/*   Updated: 2024/12/16 18:36:47 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

char	*path_execve(const char *dir, const char *command)
{
	char	*path;
	size_t	dir_len;
	size_t	command_len;

	dir_len = ft_strlen(dir);
	command_len = ft_strlen(command);
	path = malloc(dir_len + command_len + 2);
	if (path == NULL)
		return (NULL);
	ft_strlcpy(path, dir, dir_len + command_len + 2);
	ft_strlcat(path, command, dir_len + command_len + 2);
	return (path);
}

int	ft_execvp(t_command *command, char ***env)
{
	t_task	*task;
	char	*args[256];
	int		i;
	char	*path;

	i = 0;
	command->fd_out_put = ft_verif_out_put(command);
	command->fd_in_put = ft_verif_in_put(command);
	task = command->first;
	path = path_execve("/bin/", task->content);
	while (task && i < 255)
	{
		if (task->type == 0)
			args[i++] = task->content;
		task = task->next;
	}
	args[i] = NULL;
	if (execve(path, args, *env) == -1)
	{
		printf("%s: command not found\n", args[0]);
		exit(-1);
	}
	return (0);
}

int	ft_exec_parent(int **pipes, int nb_command)
{
	int	i;
	int	status;
	int	g_status;

	i = 0;
	close_pipes(pipes, nb_command);
	while (i < nb_command)
	{
		wait(&status);
		i++;
	}
	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		g_status = WTERMSIG(status);
		if (g_status != 131)
			g_status += 128;
	}
	free_pipe(pipes, nb_command);
	return (g_status);
}

int	ft_create_process(int **pipes, t_command *command, t_env_ex *env,
						int count)
{
	pid_t	pid;
	int		nb_command;

	nb_command = count_command(command);
	command = search_command(command, count);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		if (count > 0)
			dup2(pipes[count -1][0], STDIN_FILENO);
		if (count < nb_command -1)
			dup2(pipes[count][1], STDOUT_FILENO);
		close_pipes(pipes, nb_command);
		if (!is_builtin(command->first->content))
			exit(exec_builtin(command, env));
		else
			exit(ft_execvp(command, &env->env));
	}
	return (0);
}

void	create_save_pwd(char ***env)
{
	char	*stock;
	char	*path;

	path = NULL;
	stock = get_env_var("-P_W_D", *env);
	if (stock == NULL)
	{
		path = malloc(sizeof(char ) * 1000);
		getcwd(path, 1000);
		change_var(env, path, "-P_W_D");
		free(path);
	}
}

int	in_out_put(t_command *command, t_env_ex *env)
{
	command->fd_out_put = ft_verif_out_put(command);
	command->fd_in_put = ft_verif_in_put(command);
	if (command->fd_out_put == -1 || command->fd_in_put == -1)
	{
		env->exit_code = -1;
		return (1);
	}
	return (0);
}

void	ft_execute(t_command *command, t_env_ex *env)
{
	int	nb_command;
	int	saved_stdin;
	int	saved_stdout;

	create_save_pwd(&env->env);
	nb_command = count_command(command);
	saved_stdout = dup(STDOUT_FILENO);
	saved_stdin = dup(STDIN_FILENO);
	if (nb_command == 0)
		return ;
	if (nb_command == 1 && !is_builtin(command->first->content))
	{
		if (!ft_strncmp("exit", command->first->content, ft_strlen(command->first->content)))
		{
			close(saved_stdin);
			close(saved_stdout);
			ft_exec_exit(command, env);
		}
		if (in_out_put(command, env))
			return ;
		env->exit_code = exec_builtin(command, env);
		ft_close_out_put(command, saved_stdout);
		ft_close_in_put(command, saved_stdin);
	}
	else
		env->exit_code = ft_exec_pipe(command, env, nb_command);
}
