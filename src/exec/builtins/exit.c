/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:43:55 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/17 14:31:16 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

int	check_content(char *content, int i)
{
	while (content[i])
	{
		if (!ft_isdigit(content[i]))
		{
			ft_putstr_fd("Minishell: exit: '", STDERR_FILENO);
			ft_putstr_fd(content, STDERR_FILENO);
			ft_putstr_fd("' : numeric argument required\n", STDERR_FILENO);
			return (2);
		}
		i++;
	}
	return (0);
}

int	adjust_number(int var, int neg)
{
	if (var > 255)
		return (255);
	if (neg)
		var = -var;
	while (var < 256)
		var += 256;
	if (neg)
		var = 256 - var;
	return (var);
}

int	is_valid(char *content)
{
	int	i;
	int	neg;
	int	ret;

	i = 0;
	neg = 0;
	if (!content || content[0] == '\0')
	{
		ft_putstr_fd("Minishell: exit: '':numeric argument required\n",
			STDERR_FILENO);
		return (2);
	}
	if (content[i] == '-')
	{
		neg = 1;
		i++;
	}
	check_content(content, i);
	ret = ft_atoi(content);
	ret = adjust_number(ret, neg);
	return (ret);
}

int	check_exit_args(t_command *command, t_env_ex *env)
{
	t_task	*task;
	int		t;

	t = 0;
	task = command->first->next;
	if (task == NULL)
		return (env->exit_code);
	if (task->next != NULL)
	{
		ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(": too many arguments\n", STDERR_FILENO);
		t = 1;
	}
	t = is_valid(task->content);
	return (t);
}

void	ft_exec_exit(t_command *command, t_env_ex *env,
						t_command *first_command, int saved_stdout)
{
	int	ret;

	ret = 0;
	ret = check_exit_args(command, env);
	free_struct(&first_command);
	ft_tabfree(env->env);
	free(env);
	rl_clear_history();
	if (saved_stdout == -1)
		exit (ret);
	close(saved_stdout);
	exit(ret);
}
