/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:43:55 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/12 16:16:30 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structure_execute.h"

int	is_valid(char *content)
{
	int i;

	i = 0;
	if (content[0] == '-' && ft_isdigit(content[1]))
		i++;
	while (content[i])
	{
		if (!ft_isdigit(content[i]))
		{
			ft_putstr_fd("Minishell: exit: '", STDERR_FILENO);
			ft_putstr_fd(content, 2);
			ft_putstr_fd("' : numeric argument required\n", STDERR_FILENO);
			return (2);
		}
		i++;
	}
	if (ft_atoi(content) > 255)
		return (255);
	else
		return (ft_atoi(content));
}

int	check_exit_args(t_command *command, t_env_ex *env)
{
	t_task *task;
	int t;

	t = 0;
	task = command->first;
	if (task == NULL)
		return (env->exit_code);
	if (task->next != NULL)
	{
		ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(": too many arguments\n", STDERR_FILENO);
		t = 1;
	}
	t = is_valid(task->next->content);
	return (t);
		
}


void	ft_exec_exit(t_command *command, t_env_ex *env)
{
	int	ret;
	ret = check_exit_args(command, env);
	ft_tabfree(env->env);
	free(env);
	free_struct(&command);
	rl_clear_history();
	exit (ret);
}