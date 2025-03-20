/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:43:55 by jkerthe           #+#    #+#             */
/*   Updated: 2024/11/28 15:43:55 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

int	safe_write(char *content, int fd)
{
	size_t	bytes_written;

	bytes_written = write(fd, content, ft_strlen(content));
	if ((int)bytes_written == -1)
	{
		perror("write error: ");
		if (errno == ENOMEM)
			ft_putstr_fd("write error: no space left on device\n",
				STDERR_FILENO);
		return (1);
	}
	return (0);
}

int	option_echo(char *a)
{
	if (*a != '-')
		return (1);
	a++;
	if (!*a)
		return (1);
	while (*a)
	{
		if (*a != 'n')
			return (1);
		a++;
	}
	return (0);
}

int	write_task(t_task	*task, t_command *command)
{
	int	cpt;

	cpt = 0;
	while (task)
	{
		if (task->type == 0)
		{
			if (cpt != 0)
				write(command->fd_out_put, " ", 1);
			if (safe_write(task->content, command->fd_out_put))
				return (1);
			cpt++;
		}
		task = task->next;
	}
	return (0);
}

int	ft_exec_echo(t_command *command, t_task *task)
{
	int		suppress_newline;

	task = task->next;
	suppress_newline = 0;
	while (task && !option_echo(task->content))
	{
		suppress_newline = 1;
		task = task->next;
	}
	if (write_task(task, command))
		return (1);
	if (!suppress_newline)
		safe_write("\n", command->fd_out_put);
	return (0);
}
