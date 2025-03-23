/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 05:32:54 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/23 18:59:25 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

static bool	r_out(int *fd, char *content)
{
	int	newfd;

	newfd = open(content, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (newfd == -1)
		return (print_exec_err(2, content, errno), false);
	ft_close(fd);
	*fd = newfd;
	return (true);
}

static bool	r_in(int *fd, char *content)
{
	int	newfd;

	newfd = open(content, O_RDONLY);
	if (newfd == -1)
		return (print_exec_err(2, content, errno), false);
	ft_close(fd);
	*fd = newfd;
	return (true);
}

static bool	r_app(int *fd, char *content)
{
	int	newfd;

	newfd = open(content, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (newfd == -1)
		return (print_exec_err(2, content, errno), false);
	ft_close(fd);
	*fd = newfd;
	return (true);
}

static bool	r_hd(int *fd, char *content)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		return (perror("redir_hd: pipe error"), false);
	write(pipefd[WRITE], content, ft_strlen(content));
	close(pipefd[WRITE]);
	if (dup2(pipefd[READ], STDIN_FILENO) == -1)
		return (perror("redir_hd: dup2 error"), close(pipefd[READ]), false);
	close(pipefd[READ]);
	*fd = STDIN_FILENO;
	return (true);
}

bool	handle_redir(t_command *cmd, bool in, bool out)
{
	t_task		*task;

	task = cmd->first;
	while (task)
	{
		if ((task->type == R_OUT && !r_out(&cmd->fd_out_put, task->content))
			|| (task->type == R_IN && !r_in(&cmd->fd_in_put, task->content))
			|| (task->type == R_APP && !r_app(&cmd->fd_out_put, task->content))
			|| (task->type == R_HD && !r_hd(&cmd->fd_in_put, task->content)))
			return (ft_close(&cmd->fd_in_put),
				ft_close(&cmd->fd_out_put), false);
		task = task->next;
	}
	if (in && cmd->fd_in_put > 2)
		if (dup2(cmd->fd_in_put, STDIN_FILENO) == -1)
			return (perror("handle_redir: input dup2 error"),
				ft_close(&cmd->fd_in_put), false);
	ft_close(&cmd->fd_in_put);
	if (out && cmd->fd_out_put > 2)
		if (dup2(cmd->fd_out_put, STDOUT_FILENO) == -1)
			return (perror("handle_redir: output dup2 error"),
				ft_close(&cmd->fd_out_put), false);
	ft_close(&cmd->fd_out_put);
	return (true);
}
