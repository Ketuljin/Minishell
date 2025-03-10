/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:43:55 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/10 12:44:44 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structure_execute.h"

void	ft_exec_exit(t_command *command, t_env_ex *env)
{
	//ft_close_out_put(command, out_put);
	//ft_close_in_put(command, in_put);
	ft_tabfree(env->env);
	free(env);
	free_struct(&command);
	rl_clear_history();
	exit (0);

}