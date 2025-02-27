/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_task.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:49:46 by jkerthe           #+#    #+#             */
/*   Updated: 2024/11/28 15:49:46 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structure_execute.h"

void	free_double(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free(str);
}

int	count_line(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_task(t_command *command)
{
	t_task	*actual_task;
	int		i;

	i = 0;
	actual_task = command->first;
	while (actual_task)
	{
		if (actual_task->type == 0)
			i++;
		actual_task = actual_task->next;
	}
	return (i);
}

int	count_command(t_command *command)
{
	t_command	*actual_task;
	int			i;

	i = 1;
	actual_task = command;
	while (actual_task->next)
	{
		i++;
		actual_task = actual_task->next;
	}
	return (i);
}

char	**copy_memory(char **src, char **dest, int z)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (i != z)
		{
			dest[i] = malloc((ft_strlen(src[i]) + 1) * sizeof(char));
			if (!dest[i])
				return (NULL);
			ft_strlcpy(dest[i], src[i], (ft_strlen(src[i]) + 1));
		}
		i++;
	}
	return (dest);
}
