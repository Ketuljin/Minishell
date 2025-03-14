/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:58:17 by marvin            #+#    #+#             */
/*   Updated: 2025/02/27 00:58:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

int	ft_open_out_put(int type, int out_put, char *content, int saved_stdout)
{
	if (type == 1)
	{
		if (out_put != saved_stdout)
			close(out_put);
		out_put = open(content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (out_put == -1)
			return (-1);
		return (out_put);
	}
	if (type == 3)
	{
		if (out_put != saved_stdout)
			close(out_put);
		out_put = open(content, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (out_put == -1)
			return (-1);
		return (out_put);
	}
	return (-1);
}

int	ft_verif_out_put(t_command *command)
{
	t_task	*task;
	int		saved_stdout;

	saved_stdout = 1;
	task = command->first;
	if (saved_stdout == -1)
	{
		perror("dup failed");
		return (1);
	}
	while (task)
	{
		if (task->type == 1)
			command->fd_out_put = ft_open_out_put (1, command->fd_out_put,
					task->content, saved_stdout);
		if (task->type == 3)
			command->fd_out_put = ft_open_out_put (3, command->fd_out_put,
					task->content, saved_stdout);
		task = task->next;
	}
	if (command->fd_out_put != STDOUT_FILENO)
	{
		if (dup2(command->fd_out_put, STDOUT_FILENO) == -1)
		{
			perror("dup2 failed");
			return (-1);
		}
	}
	return (saved_stdout);
}

void	ft_close_out_put(t_command *command, int fd_save)
{
	if (dup2(fd_save, STDOUT_FILENO) == -1)
	{
		perror("dup2 failed a lot");
		return ;
	}
	close(fd_save);
	if (command->fd_out_put != STDOUT_FILENO)
		close(command->fd_out_put);
	command->fd_out_put = STDERR_FILENO;
}
