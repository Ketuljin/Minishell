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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **change_var(char ***env, char *new_value, char *name)
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
    while ((*env)[i]) // Remarquez l'utilisation de **env pour accéder au tableau
    {
        if (ft_strncmp((*env)[i], name, name_len) == 0 && (*env)[i][name_len] == '=')
        {
            free((*env)[i]);
            (*env)[i] = new_var;
            return (*env);
        }
        i++;
    }

    // Ajout de la variable si elle n'existe pas
    *env = add_env_var(*env, new_var);
    free(new_var);
    return (*env);
}



int cd_no_arg(char ***env)
{
    char *home;
    char *pwd;

    pwd = get_env_var("PWD", *env);
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
    change_var(env, pwd, "OLDPWD");
    change_var(env, home, "PWD");
    return (0);
}

int execute_cd_args(t_command *command, char ***env)
{
    t_task *task;
    char *path;
    char *pwd;

    task = command->first->next;
    path = option_cd(task->content, *env);
    if (!path)
        return (1);

    pwd = get_env_var("PWD", *env);

    if (chdir(path) == -1)
    {
        perror("minishell: cd");
        return (1);
    }
    change_var(env, pwd, "OLDPWD");
    change_var(env, get_env_var("PWD", *env), "PWD"); // Mise à jour correcte
    return (0);
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

int ft_exec_cd(t_command *command, char ***env)
{
    int task_count;

    task_count = count_task(command);

    if (task_count > 1)
    {
        ft_putstr_fd("minishell: cd: too many arguments\n", 2);
        return (1);
    }
    if (task_count == 0)
        return cd_no_arg(env);

    if (task_count == 1)
        return execute_cd_args(command, env);

    return (0);
}