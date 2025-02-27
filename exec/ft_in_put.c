/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:59:51 by marvin            #+#    #+#             */
/*   Updated: 2025/02/27 00:59:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

void	ft_close_in_put (t_command *command, int fd_stdin) 
{
	if(command->fd_in_put != fd_stdin && command->fd_in_put != STDIN_FILENO)
		close (command->fd_in_put);
    if (dup2(fd_stdin, STDIN_FILENO == -1))
	{
		perror("dup2 failed in ft_close_in_put");
		exit(EXIT_FAILURE);
	}
    close(fd_stdin);
}


void	open_str_stdin(const char *str)
{
	int fd[2];

    if (pipe(fd) == -1) {
        perror("Pipe creation error");
        exit(EXIT_FAILURE);
    }
    write(fd[1], str, ft_strlen(str));
    close(fd[1]);
    if (dup2(fd[0], STDIN_FILENO) == -1) 
	{
		perror("dup2 failed in open_str_stdin");
		close(fd[0]);
		exit(EXIT_FAILURE);
	}
    close(fd[0]);
}


int ft_open_in_put(int type, int in_put, char *content, int saved_stdin)
{
	if (type == 2)
	{
		if (in_put != saved_stdin)
			close(in_put);
		in_put = open(content, O_RDONLY);
		if (in_put == -1)
        	return (-1);
		return (in_put);
	}
	if (type == 4)
	{
		if (in_put != saved_stdin && in_put != STDIN_FILENO)
			close(in_put);
		open_str_stdin(content);
		in_put = STDIN_FILENO;
		return (in_put);
	}
	return (-1);
}


int	ft_verif_in_put(t_command *command)
{
	t_task		*task;
	int			saved_stdin;
	t_command	*stock_command;
	int			new_in_put;

	stock_command = command;
	saved_stdin = dup(STDIN_FILENO);
	new_in_put = saved_stdin;
    if (saved_stdin == -1) {
        perror("dup failed");
        return (-1);
	}
	while (stock_command->next)
	{
		task = stock_command->first;
		while (task)
		{
			if (task->type == 2)
				new_in_put = ft_open_in_put (2, stock_command->fd_in_put, task->content, saved_stdin);
			if (task->type == 4)
				new_in_put = ft_open_in_put (4, stock_command->fd_in_put, task->content, saved_stdin);
			if (stock_command->fd_in_put == -1)
				return (-1);
			task = task->next;
		}
		stock_command = stock_command->next;
		
	}
		if (stock_command->fd_in_put != STDIN_FILENO)
		{
			if (dup2(stock_command->fd_in_put, STDIN_FILENO) == -1)
			{
				perror("dup2 failed");
				return (-1);
			}
		}
	return (saved_stdin);
}