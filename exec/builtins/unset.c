/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:58:08 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/04 13:10:38 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structure_execute.h"

char	**delete_env_line(char **env, int pos)
{
	int		i;
	int		j;
	int		size;
	char	**temp;

	i = 0;
	j = 0;
	size = count_line(env);
	temp = malloc(sizeof(char *) * (size));
	if (temp == NULL)
		return (NULL);
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
	return (temp);
}

char	**delete_env_var(char **env, char *str)
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
			return (env);
		}
		i++;
	}
	return (env);
}

int	ft_exec_unset(t_command *command, char ***env)
{
	t_task	*task;
	int		cpt;

	cpt = count_task(command);
	task = command->first->next;
	if (cpt == 1)
		return (0);
	while (task != NULL && task->content != NULL)
	{
		*env = delete_env_var(*env, task->content);
		task = task->next;
	}
	return (0);
}
