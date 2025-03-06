/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:11:17 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/06 15:43:19 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structure_execute.h"

char	*change_var_utils(char *name, char *new_value, int name_len)
{
	char	*new_var;

	new_var = malloc((name_len + ft_strlen(new_value) + 2) * sizeof(char));
	ft_strlcpy(new_var, name, name_len + 1);
	ft_strlcat(new_var, "=", name_len + 2);
	ft_strlcat(new_var, new_value, name_len + ft_strlen(new_value) + 2);
	return (new_var);
}

char	**change_var(char ***env, char *new_value, char *name)
{
	int		i;
	int		name_len;
	char	*new_var;

	name_len = ft_strlen(name);
	new_var = change_var_utils(name, new_value, name_len);
	if (!new_var)
		return (NULL);
	i = 0;
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], name, name_len) == 0
			&& (*env)[i][name_len] == '=')
		{
			free((*env)[i]);
			(*env)[i] = new_var;
			return (*env);
		}
		i++;
	}
	*env = add_env_var(*env, new_var);
	free(new_var);
	return (*env);
}

char	**change_pwd(char ***env, char *new_value, char *name)
{
	int		i;
	int		name_len;
	char	*new_var;

	name_len = ft_strlen(name);
	new_var = change_var_utils(name, new_value, name_len);
	if (!new_var)
		return (NULL);
	i = 0;
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], name, name_len) == 0
			&& (*env)[i][name_len] == '=')
		{
			free((*env)[i]);
			(*env)[i] = new_var;
			return (*env);
		}
		i++;
	}
	free(new_var);
	return (*env);
}
