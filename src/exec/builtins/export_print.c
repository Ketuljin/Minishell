/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:37:13 by marvin            #+#    #+#             */
/*   Updated: 2024/12/09 14:37:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

void	printf_export(char **stock, t_command *command)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i][0] != '-')
		{
			safe_write("declare -x ", command->fd_out_put);
			safe_write(stock[i], command->fd_out_put);
			safe_write("\n", command->fd_out_put);
		}
		i++;
	}
}

int	compare_ascii(char *s1, char *s2)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s1[i] == s2[i])
		i++;
	j = s1[i] - s2[i];
	return (j);
}

int	order_check(char	**stock)
{
	int	i;

	i = 0;
	while (stock[i] && stock[i + 1])
	{
		if (compare_ascii(stock[i], stock[i + 1]) > 0)
			return (1);
		i++;
	}
	return (0);
}

void	ascii_order(char **stock, t_command *command)
{
	char	*temp;
	int		i;

	temp = NULL;
	while (order_check(stock))
	{
		i = 0;
		while (stock[i] && stock[i +1])
		{
			if (compare_ascii(stock[i], stock[i +1]) > 0)
			{
				temp = stock[i];
				stock[i] = stock[i +1];
				stock[i +1] = temp;
			}
			i++;
		}
	}
	printf_export(stock, command);
}

int	export_no_arg(t_command *command, char **env)
{
	char	**stock;
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (env[count] != NULL)
		count++;
	stock = malloc((count +1) * sizeof(char *));
	if (stock == NULL)
		return (1);
	while (i < count)
	{
		stock[i] = env[i];
		i++;
	}
	stock[i] = NULL;
	ascii_order(stock, command);
	free(stock);
	return (0);
}
