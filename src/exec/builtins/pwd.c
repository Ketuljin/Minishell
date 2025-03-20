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

#include "structure_execute.h"

int	ft_exec_pwd(char	**env)
{
	char	*path;

	path = get_env_var("-P_W_D", env);
	if (path == NULL)
	{
		ft_putstr_fd("torture: missing PWD", 2);
		return (-1);
	}
	safe_write(path, 1);
	safe_write("\n", 1);
	return (0);
}
