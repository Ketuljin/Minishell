/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:58:08 by jkerthe           #+#    #+#             */
/*   Updated: 2024/12/10 16:40:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_minishell.h"

char **delete_env_line(char **env, int pos)
{
    int i;
	int j;

	i = 0, 
	j = 0;
    int size ;
	char	**temp;

	size = count_line(env);
    temp = malloc(sizeof(char *) * (size));
    if (temp == NULL)
        return NULL;
    while (env[i])
    {
        if (i != pos) 
		{
            temp[j] = ft_strdup(env[i]);
			j++;
		}
		free(env[i]);
		i++;

    }
    temp[j] = NULL;
    free(env);
    return temp;
}

char **delete_env_var(char **env, char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while ((env)[i] != NULL)
	{
		if (ft_strncmp(env[i], str, len) == 0 && env[i][len] == '=')
		{
			env = delete_env_line(env, i);
			return(env);
		}
		i++;
	}
	return(env);
}	

char **exec_unset(t_command *command, char **env)
{
	t_task	*task;

	task = command->first->next;
	if (!task)
		return (env);
	while (task!=NULL && task->content != NULL)
	{
		env = delete_env_var(env, task->content);
		task = task->next;
	}
	return (env);
}
