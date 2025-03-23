/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:06:44 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/23 02:55:37 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

void	ft_close(int *fd)
{
	if (*fd > 2)
	{
		close(*fd);
		*fd = -1;
	}
}

int	ft_exec_pipe(t_command *command, int nb_command, t_env_ex *env)
{
	int i;
	int	pipefd[2];
	int	lastfd;

	lastfd = STDIN_FILENO;
	i = 0;
	while (i < nb_command)
	{
		if (i < nb_command - 1)
			if (pipe(pipefd) == -1)
				return (-1);
		ft_create_process(lastfd, pipefd, command, i, env);
		ft_close(&lastfd);
		ft_close(&pipefd[WRITE]);
		lastfd = pipefd[READ];
		i++;
	}
	return (ft_exec_parent(command));
}

int	is_pipe(t_command *command)
{
	if (command->next != NULL)
		return (0);
	return (1);
}
