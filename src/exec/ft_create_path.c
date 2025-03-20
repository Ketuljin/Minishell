/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:38:10 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/20 19:46:29 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

void	copy_slash(char *content, char *stock)
{
	int	i;
	int	cpt;

	cpt = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == '/')
		{
			stock[cpt] = content[i];
			cpt++;
			i++;
			while (content[i] == '/')
				i++;
		}
		else
		{
			stock[cpt] = content[i];
			cpt++;
			i++;
		}
	}
	stock[cpt] = '\0';
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

char	*delete_sl(char	*content)
{
	int		i;
	int		cpt;
	char	*stock;

	i = 0;
	cpt = 0;
	cpt = count_slash(content);
	stock = malloc(sizeof(char) * cpt +1);
	copy_slash(content, stock);
	return (stock);
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

int	create_path(t_task *task, char **path, t_env_ex *env_ex)
{
	int fd;

	fd = 0;
	if (!no_path(task->content))
	{
		*path = delete_sl(task->content);
		fd = open(*path, O_RDONLY);
		if (fd == -1)
		{
			free(path);
			*path = NULL;
		}
		else
		{
			close (fd);
		}
	}
	else
		*path = search_path(task->content, env_ex->env);
	if (*path == NULL)
	{
		ft_putstr_fd("command '", STDERR_FILENO);
		ft_putstr_fd(task->content, STDERR_FILENO);
		ft_putstr_fd("' : not found\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}