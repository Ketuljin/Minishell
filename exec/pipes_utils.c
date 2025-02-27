/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:06:44 by jkerthe           #+#    #+#             */
/*   Updated: 2025/02/27 19:51:44 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

void	close_pipes(int **pipes, int nb_command)
{
	int	i;

	i = 0;
	while (i < nb_command -1)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

int	**ft_create_pipe(int nb_command)
{
	int	i;
	int	**pipes;

	i = 0;
	pipes = malloc(sizeof(int *) * nb_command -1);
	while (nb_command -1 > i)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		i++;
	}
	return (pipes);
}

int	**free_pipe(int **pipes, int nb_command)
{
	int	i;

	i = 0;
	while (nb_command -1 > i)
	{
		free(pipes[i]);
		i++;
	}
	free (pipes);
	return (NULL);
}

int	ft_exec_pipe(t_command *command, char ***env, int nb_command)
{
	int	**pipes;
	int	i;

	pipes = ft_create_pipe(nb_command);
	i = 0;
	while (i < nb_command -1)
	{
		if (pipe(pipes[i]) == -1)
			return (-1);
		i++;
	}
	i = 0;
	while (i < nb_command)
	{
		ft_create_process(pipes, command, env, i);
		i++;
	}
	return (ft_exec_parent(pipes, nb_command));
}

int	is_pipe(t_command *command)
{
	if (command->next != NULL)
		return (0);
	return (1);
}
