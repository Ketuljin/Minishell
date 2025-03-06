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

#include "../structure_execute.h"

int	cd_no_arg(char ***env)
{
	char	*home;
	char	*pwd;

	pwd = malloc(sizeof(char) * 1000);
	getcwd(pwd, 1000);
	home = get_env_var("HOME", *env);
	if (!home)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	if (chdir(home) == -1)
	{
		perror("minishell: cd");
		return (1);
	}
	change_pwd(env, home, "PWD");
	change_var(env, pwd, "OLDPWD");
	change_var(env, home, "-P_W_D");
	free (pwd);
	return (0);
}

int	execute_cd_args(t_command *command, char ***env)
{
	t_task	*task;
	char	*path;
	char	*pwd;
	char	*tmp;

	pwd = malloc(sizeof(char) * 1000);
	task = command->first->next;
	path = option_cd(task->content, *env);
	if (!path)
		return (1);
	getcwd(pwd, 1000);
	if (chdir(path) == -1)
	{
		perror("minishell: cd");
		return (1);
	}
	change_var(env, pwd, "OLDPWD");
	tmp = malloc(sizeof(char) * 1000);
	getcwd(tmp, 1000);
	change_pwd(env, tmp, "PWD");
	change_var(env, tmp, "-P_W_D");
	free (tmp);
	free (pwd);
	return (0);
}

char	*option_cd(char *content, char **env)
{
	if (!ft_strncmp(content, "-", ft_strlen(content)))
		return (get_env_var("OLDPWD", env));
	if (content[0] == '-' && content[1] != '\0')
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(content, 2);
		ft_putstr_fd(": invalid option\n", 2);
		return (NULL);
	}
	return (content);
}

int	ft_exec_cd(t_command *command, char ***env)
{
	int	task_count;

	task_count = count_task(command);
	if (task_count > 2)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	if (task_count == 1)
		return (cd_no_arg(env));
	if (task_count == 2)
		return (execute_cd_args(command, env));
	return (0);
}
