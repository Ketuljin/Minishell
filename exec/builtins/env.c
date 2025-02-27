/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:42:02 by jkerthe           #+#    #+#             */
/*   Updated: 2024/11/28 15:42:02 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structure_execute.h"

char	*get_env_var(const char *var, char **env)
{
	int	len;
	int	i;

	if (!var || !env)
		return (NULL);
	len = ft_strlen(var);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

int	ft_exec_env(t_command *command, char **env)
{
	int		cpt;

	cpt = count_task(command);
	if (!env || !*env)
	{
		ft_putstr_fd("Minishell: env: no environment variables found\n", 2);
		return (1);
	}
	if (cpt != 1)
		ft_putstr_fd("Minishell: env: too many argument", 2);
	while (*env)
	{
		ft_putstr_fd(*env, command->fd_out_put);
		ft_putstr_fd("\n", command->fd_out_put);
		env++;
	}
	return (0);
}
