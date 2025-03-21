/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:38:10 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/21 16:48:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

int	only_content(char *content, char c)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] != c)
			return (1);
		i++;
	}
	return (0);
}

int	no_path(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '/')
			return (0);
		i++;
	}
	return (1);
}

char	*search_path(char *content, char **env)
{
	char	*path;
	char	**stock;
	char	*full_path;

	path = get_env_var("PATH", env);
	if (path == NULL)
		return (NULL);
	stock = ft_split(path, ':');
	full_path = valid_command(content, stock);
	free_double(stock);
	return (full_path);
}

void	clean_path(char *content, char **path)
{
	int	fd;

	*path = delete_sl(content);
	fd = open(*path, O_RDONLY);
	if (fd == -1)
	{
		free(*path);
		*path = NULL;
	}
	else
		close (fd);
}

int	create_path(t_task *task, char **path, t_env_ex *env_ex)
{
	if (!no_path(task->content))
		clean_path(task->content, path);
	else
		*path = search_path(task->content, env_ex->env);
	if (!only_content(task->content, '/') || !only_content(task->content, '.'))
	{
		free(*path);
		*path = NULL;
	}
	if (*path == NULL)
	{
		ft_putstr_fd("command '", STDERR_FILENO);
		ft_putstr_fd(task->content, STDERR_FILENO);
		ft_putstr_fd("' : not found\n", STDERR_FILENO);
		return (137);
	}
	return (0);
}
