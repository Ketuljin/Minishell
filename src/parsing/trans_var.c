/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_var.c                                        :+:      :+:    :+:   */
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

char	*extract_var(char *content, int *i)
{
	char	*var;
	int		j;

	var = calloc(ft_strlen(content) + 2, sizeof(char));
	j = 0;
	while (content[*i] != '\0'
		&& (ft_isalnum(content[*i]) != 0 || content[*i] == '_'))
	{
		var[j] = content[*i];
		(*i)++;
		j++;
	}
	var[j] = '=';
	return (var);
}

char	*find_var(char **envp, char *var)
{
	int	i;

	i = -1;
	while (envp[++i] != NULL)
		if (ft_strncmp(var, envp[i], ft_strlen(var)) == 0)
			return (get_var2(envp[i]));
	return (NULL);
}

int	trans_var(t_task **token, t_env_ex **env_ex, char **newcnt, t_count **count)
{
	char	*temp;
	char	*var;
	int		k;

	if ((*token)->content[(*count)->i + 1] == '\0')
		return (0);
	(*count)->i++;
	temp = extract_var(((*token)->content), &(*count)->i);
	if ((*token)->content[(*count)->i] == '?')
	{
		(*count)->i++;
		var = ft_itoa((*env_ex)->exit_code);
	}
	else
		var = find_var((*env_ex)->env, temp);
	free(temp);
	if (var == NULL)
		return (0);
	k = 0;
	temp = calloc(ft_strlen(var) + (*count)->j + ft_strlen((*token)->content)
			- (*count)->i + 1, sizeof(char));
	ft_strlcpy(temp, *newcnt, ft_strlen(*newcnt) + 1);
	while (var[k] != '\0')
		temp[((*count)->j)++] = var[k++];
	free(*newcnt);
	*newcnt = temp;
	return (0);
}
