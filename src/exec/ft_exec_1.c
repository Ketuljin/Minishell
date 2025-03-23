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

int	ft_exec_parent(t_command *command)
{
	int	status;
	int	exitcode;

	while (command)
	{
		waitpid(command->pid, &status, 0);
		command = command->next;
	}
	if (WIFEXITED(status))
		exitcode = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		exitcode = WTERMSIG(status);
		if (exitcode != 131)
			exitcode += 128;
	}
	return (exitcode);
}

int	ft_exec_process(t_command *command, t_env_ex *env_ex,
						t_command *first_command)
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
			ft_exec_exit (command, env_ex, first_command, -1);
		}
		ex = exec_builtin(command, env_ex, first_command);
		clean_all(NULL, env_ex, &first_command);
		exit (ex);
	}
	else
	{
		ex = try_execve(command, env_ex);
		clean_all(NULL, env_ex, &first_command);
		exit (ex);
	}
}

int	ft_create_process(int lastfd, int pfd[2], int i, t_env_ex *env)
{
	int			nb_command;
	t_command	*first_command;

	nb_command = count_command(env->cmd);
	first_command = env->cmd;
	env->cmd = search_command(env->cmd, i);
	env->cmd->pid = fork();
	if (env->cmd->pid == -1)
		return (-1);
	if (env->cmd->pid == 0)
	{
		if (i > 0)
			dup2(lastfd, STDIN_FILENO);
		ft_close(&lastfd);
		if (i < nb_command - 1)
		{
			dup2(pfd[WRITE], STDOUT_FILENO);
			ft_close(&pfd[WRITE]);
			ft_close(&pfd[READ]);
		}
		ft_exec_process(env->cmd, env, first_command);
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
