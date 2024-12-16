/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:49:19 by jkerthe           #+#    #+#             */
/*   Updated: 2024/11/28 15:49:19 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_minishell.h"

int	ft_exec_pwd(char	**env)
{
	char	*path;

	path = get_env_var("PWD", env);
	if(path == NULL)
	{
		ft_putstr_fd("Minishell: missing PWD");
		return(1);
	}
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	if (path)
	{
		free (path);
		path = NULL;
	}
	return (0);
}
