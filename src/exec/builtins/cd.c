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

#include "structure_execute.h"

char	*option_cd(char *content, char **env)
{
	if (!ft_strncmp(content, "-", ft_strlen(content)))
	{
		if (get_env_var("OLDPWD", env) == NULL)
		{
			ft_putstr_fd("torture: cd: OLDPWD not set\n", 2);
			return (NULL);
		}
	}
	if (content[0] == '-' && content[1] != '\0')
	{
		ft_putstr_fd("torture: cd: ", 2);
		ft_putstr_fd(content, 2);
		ft_putstr_fd(": invalid option\n", 2);
		return (NULL);
	}
	return (content);
}

int	cd_no_arg(char ***env)
{
	char	*home;
	char	*pwd;

	pwd = malloc(sizeof(char) * 1000);
	getcwd(pwd, 1000);
	home = get_env_var("HOME", *env);
	if (!home)
	{
		ft_putstr_fd("torture: cd: HOME not set\n", 2);
		free (pwd);
		return (1);
	}
	if (chdir(home) == -1)
	{
		perror("torture: cd");
		free(pwd);
		return (1);
	}
	change_pwd(env, home, "PWD");
	change_pwd(env, pwd, "OLDPWD");
	change_var(env, home, "-P_W_D");
	free (pwd);
	return (0);
}

int	execute_cd_args(t_task *task, char ***env)
{
	char	*path;
	char	*pwd;
	char	*tmp;

	pwd = malloc(sizeof(char) * 1000);
	path = option_cd(task->content, *env);
	if (path == NULL)
		return (1);
	getcwd(pwd, 1000);
	if (chdir(path) == -1)
	{
		free(pwd);
		perror("torture: cd");
		return (1);
	}
	change_pwd(env, pwd, "OLDPWD");
	tmp = malloc(sizeof(char) * 1000);
	getcwd(tmp, 1000);
	change_pwd(env, tmp, "PWD");
	change_var(env, tmp, "-P_W_D");
	free (tmp);
	free (pwd);
	return (0);
}

int	ft_exec_cd(t_task *task, char ***env)
{
	int	task_count;

	task_count = count_task(task);
	if (task_count > 2)
	{
		ft_putstr_fd("torture: cd: too many arguments\n", 2);
		return (1);
	}
	if (task_count == 1)
		return (cd_no_arg(env));
	if (task_count == 2)
		return (execute_cd_args(task->next, env));
	return (0);
}
