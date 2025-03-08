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

#include "../structure_execute.h"

int	valid_name(char *content)
{
	int	i;

	i = 0;
	if (0 == ft_isalpha(content[i]) && content[i] != '_')
	{
		ft_putstr_fd("Minishell: export: '", STDOUT_FILENO);
		ft_putstr_fd(content, STDOUT_FILENO);
		ft_putstr_fd("' : not a valid identifier\n", STDOUT_FILENO);
		return (1);
	}
	i++;
	while (content[i] && content[i] != '=')
	{
		if (0 == ft_isalpha(content[i]) && 0 == ft_isdigit(content[i]) && content[i] != '_')
		{
			ft_putstr_fd("Minishell: export: '", STDOUT_FILENO);
			ft_putstr_fd(content, STDOUT_FILENO);
			ft_putstr_fd("' : not a valid identifier\n", STDOUT_FILENO);
			return (1);
		}
		i++;
	}
	return (0);
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

int	arleady_exist(char **env, char *content)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (content[len] != '=' && content[len] != '\0')
		len++;
	while (env[i])
	{
		if (!ft_strncmp(env[i], content, len) && env[i][len] == '=')
			return (0);
		i++;
	}
	return (1);
}

int	export_arg(char ***env, char *content)
{
	int		i;
	char	*new_value;
	char	*name;

	i = check_task(content);
	if (!arleady_exist(*env, content))
	{
		new_value = ft_substr(content, i + 1, ft_strlen(content));
		name = ft_substr(content, 0, i);
		*env = change_var(env, new_value, name);
		free(new_value);
		free(name);
	}
	else if (!valid_name(content))
		*env = add_env_var(*env, content);
	return (0);
}

int	ft_exec_export(t_command *command, char ***env)
{
	int		count;
	t_task	*task;

	task = command->first;
	count = count_task(command);
	if (count == 1)
	{
		export_no_arg(command, *env);
		return (0);
	}
	task = task->next;
	while (task != NULL)
	{
		if (task->type == 0)
			export_arg(env, task->content);
		task = task->next;
	}
	return (0);
}
