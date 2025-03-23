/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:26:56 by jkerthe           #+#    #+#             */
/*   Updated: 2024/12/05 15:26:56 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

bool	valid_name(char *content)
{
	int	i;

	i = 0;
	if (0 == ft_isalpha(content[i]) && content[i] != '_')
	{
		ft_putstr_fd("Minishell: export: '", STDERR_FILENO);
		ft_putstr_fd(content, STDERR_FILENO);
		ft_putstr_fd("' : not a valid identifier\n", STDERR_FILENO);
		return (false);
	}
	i++;
	while (content[i] && content[i] != '=')
	{
		if (0 == ft_isalpha(content[i])
			&& 0 == ft_isdigit(content[i]) && content[i] != '_')
		{
			ft_putstr_fd("Minishell: export: '", STDERR_FILENO);
			ft_putstr_fd(content, STDERR_FILENO);
			ft_putstr_fd("' : not a valid identifier\n", STDERR_FILENO);
			return (false);
		}
		i++;
	}
	return (true);
}

int	check_task(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			if (i != 0)
				return (i);
		}
		i++;
	}
	return (0);
}

bool	export_arg(char ***env, char *content)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while ((*env)[i])
	{
		len = size_comp(content, (*env)[i]);
		if (!ft_strncmp((*env)[i], content, len))
		{
			if (valid_name(content) && ft_strchr(content, '='))
			{
				free((*env)[i]);
				(*env)[i] = malloc(sizeof(char) * (ft_strlen(content) + 1));
				ft_strlcpy((*env)[i], content, ft_strlen(content) + 1);
			}
			return (true);
		}
		i++;
	}
	if (valid_name(content))
		return (*env = add_env_var(*env, content), true);
	return (false);
}

int	ft_exec_export(t_command *command, char ***env, t_task *task)
{
	int		count;

	count = count_task(task);
	if (count == 1)
	{
		export_no_arg(command, *env);
		return (0);
	}
	task = task->next;
	while (task != NULL)
	{
		if (task->type == T_CMD)
			if (!export_arg(env, task->content))
				return (1);
		task = task->next;
	}
	return (0);
}
