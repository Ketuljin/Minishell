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

#include "structure_builtins.h"

char    **change_var(char **env, char *new_value, char *name)
{
    int i;
    int name_len;
    char *new_var;

    name_len = ft_strlen(name);
    new_var = malloc((name_len + ft_strlen(new_value) + 2) * sizeof(char));
    if (!new_var)
        return (NULL);
    ft_strlcpy(new_var, name, name_len + 1);
    ft_strlcat(new_var, "=", name_len + 2);
    ft_strlcat(new_var, new_value, name_len + ft_strlen(new_value) + 2);
    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], name, name_len) == 0 && env[i][name_len] == '=')
        {
            free(env[i]);
            env[i] = new_var;
            return (env);
        }
        i++;
    }
    env = add_env_var(env, new_var);
    free (new_var); 
    return (env);
}


char	**cd_no_arg(char ***env)
{
    char *home;
    char *pwd;

    pwd = get_env_var("PWD", *env);
    home = get_env_var("HOME", *env);
    if (!home)
    {
        ft_putstr_fd("minishell: cd: HOME not set\n", 2);
        return (*env);
    }
    if (chdir(home) == -1)
        return (*env);
    *env = change_var(*env, pwd, "OLDPWD");
    *env = change_var(*env, home, "PWD");
    return (*env);
}

char	**execute_cd_args(t_command *command, char ***env)
{
    t_task *task;
    char *path;
    char *pwd;

    task = command->first->next;
    path = option_cd(task->content, *env);
    if (!path)
        return (*env);
    pwd = get_env_var("PWD", *env);
    if (chdir(path) == -1)
    {
        ft_putstr_fd("minishell: cd no such file or directory:", 2);
		ft_putstr_fd(path, 2);
        return (*env);
    }
    *env = change_var(*env, pwd, "OLDPWD");
    *env = change_var(*env, get_env_var("HOME", *env), "PWD");
    return (*env);
}

char *option_cd(char *content, char **env)
{
    if (!ft_strncmp(content, "-", ft_strlen(content)))
        return get_env_var("OLDPWD", env);

    if (content[0] == '-' && content[1] != '\0')
    {
        ft_putstr_fd("minishell: cd: ", 2);
        ft_putstr_fd(content, 2);
        ft_putstr_fd(": invalid option\n", 2);
        return NULL;
    }

    return content;
}

char	**ft_exec_cd(t_command *command, char **env)
{
    int task_count;

    task_count = count_task(command);
    if (task_count > 1)
    {
        ft_putstr_fd("minishell: cd: too many arguments\n", 2);
        return (env);
    }
    if (task_count == 0)
	{
		cd_no_arg(&env);
		return (env);
	}
    if (task_count == 1)
	{
		execute_cd_args(command, &env);
        return (env);
	}
    return (env);
}
