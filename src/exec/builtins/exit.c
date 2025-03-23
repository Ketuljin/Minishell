/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:43:55 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/23 03:21:26 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

int	check_content(char *content, int i)
{
	int	cpt;

	cpt = 0;
	while (content[i] == '0')
		i++;
	while (content[i])
	{
		if (!ft_isdigit(content[i]) || cpt > 19)
		{
			ft_putstr_fd("torture: exit: ", STDERR_FILENO);
			ft_putstr_fd(content, STDERR_FILENO);
			ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
			return (2);
		}
		cpt++;
		i++;
	}
	return (0);
}

int	adjust_number(int var, int neg)
{
	if (var > 255)
	{
		while (var > 255)
			var -= 256;
		return (var);
	}
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
	int			i;
	int			neg;
	long long	ret;

	i = 0;
	neg = 0;
	if (!content || content[0] == '\0')
	{
		ft_putstr_fd("torture: exit: '':numeric argument required\n", 2);
		return (2);
	}
	neg = check_sign(content[0]);
	if (neg == 1 || neg == -1)
		i++;
	if (check_content(content, i))
		return (2);
	ret = ft_atoie(content);
	if (ret > 9223372036854775807 || ret +1 < -9223372036854775807)
	{
		ft_putstr_fd("torture: exit: '", STDERR_FILENO);
		ft_putstr_fd(content, STDERR_FILENO);
		ft_putstr_fd("' : numeric argument required\n", STDERR_FILENO);
		return (2);
	}
	return (adjust_number(ret, neg));
}

int	check_exit_args(t_command *command, t_env_ex *env)
{
	t_task	*task;
	int		t;

	t = 0;
	task = command->first->next;
	if (task == NULL)
		return (env->exit_code);
	t = is_valid(task->content);
	if (t != 2)
	{
		if (task->next != NULL)
		{
			ft_putstr_fd("torture: exit: ", STDERR_FILENO);
			ft_putstr_fd(": too many arguments\n", STDERR_FILENO);
			t = 2;
		}
	}
	return (t);
}

void	ft_exec_exit(t_command *command, t_env_ex *env,
						t_command *first_command, int saved_stdout)
{
	int	ret;

	ret = 0;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	ret = check_exit_args(command, env);
	free_struct(&first_command);
	ft_tabfree(env->env);
	rl_clear_history();
	if (saved_stdout == -1)
		exit (ret);
	close(saved_stdout);
	exit(ret);
}
