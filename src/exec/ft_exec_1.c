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

int	ft_exec_process(t_command *command, t_env_ex *env_ex,
						t_command *first_command, int **pipes)
{
	int	ex;
	int	nb_command;

	nb_command = count_command(first_command);
	ex = 1;
	if (!is_builtin(command))
	{
		if (!ft_strncmp("exit", command->first->content,
				ft_strlen(command->first->content)))
		{
			free_pipe(pipes, nb_command);
			ft_exec_exit (command, env_ex, first_command, -1);
		}
		ex = exec_builtin(command, env_ex, first_command);
		clean_all(NULL, env_ex, &first_command);
		free_pipe(pipes, nb_command);
		exit (ex);
	}
	else
	{
		ft_execve(command, env_ex, first_command);
		clean_all(NULL, env_ex, &first_command);
		free_pipe(pipes, nb_command);
		exit (ex);
	}
}

int	ft_create_process(int **pipes, t_command *command, int count, t_env_ex *env)
{
	pid_t		pid;
	int			nb_command;
	t_command	*first_command;

	nb_command = count_command(command);
	first_command = command;
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
		ft_exec_process(command, env, first_command, pipes);
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

void	ft_execute(t_command *command, t_env_ex *env)
{
	int			nb_command;
	t_command	*first_command;

	first_command = command;
	create_save_pwd(&env->env);
	nb_command = count_command(command);
	if (nb_command == 0)
		return ;
	if (nb_command == 1 && !is_builtin(command))
		env->exit_code = exec_builtin(command, env, first_command);
	else
		env->exit_code = ft_exec_pipe(command, nb_command, env);
}
