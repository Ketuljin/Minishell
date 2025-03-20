/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:37:39 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/20 18:28:08 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

void	content_command(char *full_command, char **stock, int i, char *content)
{
	ft_strlcpy(full_command, stock[i], ft_strlen(stock[i]) + 1);
	if (last_content(stock[i]) != '/')
		ft_strlcat(full_command, "/", ft_strlen(full_command) + 2);
	ft_strlcat(full_command, content,
		ft_strlen(full_command) + ft_strlen(content) + 1);
}

char	*valid_command(char *content, char **stock)
{
	char	*full_command;
	int		fd;
	int		i;

	i = 0;
	fd = -1;
	while (stock[i])
	{
		full_command = malloc(ft_strlen(stock[i]) + ft_strlen(content) + 2);
		if (!full_command)
			return (NULL);
		content_command(full_command, stock, i, content);
		fd = open(full_command, O_RDONLY);
		if (fd != -1)
		{
			close (fd);
			return (full_command);
		}
		free(full_command);
		i++;
	}
	return (NULL);
}

char	**create_args(t_task *task)
{
	char	**args;
	int		i;

	i = 1;
	if (task == NULL)
		return (NULL);
	args = malloc(sizeof(char *) * (count_task(task) + 1));
	args[0] = ft_strdup(task->content);
	task = task->next;
	while (task != NULL)
	{
		if (task->type == 0)
		{
			args[i] = ft_strdup(task->content);
			i++;
		}
		task = task->next;
	}
	args[i] = NULL;
	return (args);
}

int	ft_execve(t_command *command, t_env_ex *env_ex, t_command *first_command)
{
	t_task	*task;
	char	**args;
	char	*path;

	task = first_task(command);
	path = NULL;
	if (task != NULL)
	{
		if(create_path(task, &path, env_ex))
			return (1);
	}
	ft_verif_out_put(command);
	ft_verif_in_put(command);
	args = create_args(first_task(command));
	if (args == NULL)
		return (-1);
	set_signals(S_DEFAULT);
	if (execve(path, args, env_ex->env) == -1)
	{
		perror("execve");
		clean_all(args, env_ex, &first_command);
		free(path);
	}
	set_signals(S_IGNORE);
	return (0);
}
