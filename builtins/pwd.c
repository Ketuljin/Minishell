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

#include "../structure_execute.h"

int	ft_exec_pwd(t_command *command)
{
	char	*path;

	path = malloc(sizeof(char) * 100);
	if (1 != count_task(command))
		return (-1);
	getcwd(path, 100);
	if (path == NULL)
	{
		ft_putstr_fd("Minishell: missing PWD", 1);
		return (-1);
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
