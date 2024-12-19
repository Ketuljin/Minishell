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
	var = NULL;
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

	var = NULL;
	i = 0;
	while (*line[0] != '\0' && (ft_isalnum(*line[0]) != 0 || *line[0] == '_'))
	{
		var[i] = *line[0];
		i++;
	}
	var[i] = '=';
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(var, envp[i], ft_strlen(var)) == 0)
			return (get_var2(envp[i]));
		i++;
	}
	return ("");
}

char	*replace_var(char *line, char **envp)
{
	char	*newline;
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
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
			temp = NULL;
			i = 0;
			stock(&newline, get_var(&line + 1, envp));
		}
		temp[i] = line[0];
		i++;
		line++;
	}
	stock(&newline, temp);
	return (newline);
}
