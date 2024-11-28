/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:20:55 by jkerthe           #+#    #+#             */
/*   Updated: 2024/11/28 15:20:55 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_minishell.h"

static void	change_pwd(char **env, char *new_path, char *name)
{
	int		i;
	char	*current_pwd;
	int		z;

	i = 0;
	if (!env || !new_path)
		return ;
	z = ft_strlen(name);
	while (env[i])
	{
		if (ft_strncmp(env[i], name, z) == 0)
		{
			current_pwd = env[i] + z;
			ft_strcpy(current_pwd, new_path);
			return ;
		}
		i++;
	}
	create_env_var(env, new_path, name);
}



int	execute_cd_args(t_command *command, char *current_path, char **env)
{
	t_task	*task;
	char	path;
	task = command->task->next;
	path = option(task->content);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd:", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": no such file or directory", 2);
		return (1);
	}
	return (0);
}

int	cd_no_arg(t_command *command, char **env)
{
	char	*home;
	char	*stock;

	stock = get_env_var("PWD");
	home = get_env_var("HOME");

	if (!home)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	if (chdir(home) == -1)
	{
		ft_putstr_fd("message d'erreur à definir", 2);
		return (1);
	}
	change_pwd(stock, env, "OLDPWD=");
	change_pwd(get_env_var("HOME"), env, "PWD=");
	return (0);
}

int	ft_exec_cd(t_command *command, char **env)
{
	int		i;
	char	*current_path;

	i = 0;
	current_path = getcwd(NULL, 0);
	if (!current_path)
	{
		ft_putstr_fd("minishell: getcwd", 2);
		return (1);
	}
	i = count_task(command);
	if (i > 2)
	{
		ft_putstr_fd("-Minishell: cd: too many arguments", 2);
		free (current_path);
		return (1);
	}
	if (i == 1)
		cd_no_arg(command, env);
	else if (i == 2)
		cd_args(command, current_path, env);
	free (current_path);
	return (0);
}
