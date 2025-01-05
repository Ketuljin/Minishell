/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 03:09:23 by vdunatte          #+#    #+#             */
/*   Updated: 2024/12/19 03:09:23 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*get_var2(char *envp)
{
	char	*var;
	int		i;
	int		j;

	i = 0;
	j = 0;
	var = ft_calloc(ft_strlen(envp) + 1, sizeof(char));
	while (envp[i] != '=')
		i++;
	i++;
	while (envp[i] != '\0')
	{
		var[j] = envp[i];
		i++;
		j++;
	}
	return (var);
}

char	*get_var(char **line, char **envp)
{
	char	*var;
	int		i;

	var = ft_calloc(ft_strlen(*line) + 2, sizeof(char));
	i = 0;
	while ((*line)[0] != '\0'
		&& (ft_isalnum((*line)[0]) != 0 || (*line)[0] == '_'))
	{
		var[i] = (*line)[0];
		i++;
		(*line)++;
	}
	var[i] = '=';
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(var, envp[i], ft_strlen(var)) == 0)
			return (free(var), get_var2(envp[i]));
		i++;
	}
	return (free(var), "");
}

char	*replace_var(char *line, char **envp)
{
	char	*newline;
	char	*temp;
	int		i;

	i = 0;
	temp = ft_calloc(ft_strlen(line) + 1, sizeof(char));
	newline = NULL;
	while (line[0] != '\0')
	{
		if (line[0] == '\'')
		{
			line = ft_strchr(line + 1, 39) + 1;
			if (line == NULL)
				return (line);
		}
		if (line[0] == '$')
		{
			stock(&newline, temp);
			ft_bzero(temp, ft_strlen(line) + 1);
			i = 0;
			line++;
			stock(&newline, get_var(&line, envp));
		}
		temp[i] = line[0];
		i++;
		line++;
	}
	stock(&newline, temp);
	free(temp);
	return (newline);
}
