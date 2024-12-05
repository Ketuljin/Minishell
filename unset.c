/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:58:08 by jkerthe           #+#    #+#             */
/*   Updated: 2024/12/05 17:58:20 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	env_size(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	delete_env_line(char **env, int pos)
{
	int		i;
	char	**temp;

	i = 0;
	temp = malloc(sizeof(char *) * (env_size(env) -1));

	while(env[i])
	{
		if(i = pos)
			i++;
		else
		{
			temp[i] = malloc(sizeof(char) * strlen(env[i]))
			temp[i] = env[i];
			free (env[i]);
			i++;
		}
	}
	temp[i] = NULL;
	free(env);
	return(temp);
}


void	delete_env_var(char **env, char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (env[i] != NULL)
	{
		if (strncmp(env[i], var, len) == 0 && env[i][len] == '=')
			break ;
		i++;
	}
	env = delete_env_line(env, i);
}	

int	exec_unset(t_command *command, char **env)
{
	t_task	*task;

	task = command->first_task->next;
	if (task == NULL)
	{
		ft_putstr_fd("Minishell: unset: not enough arguments");
		return (1);
	}
	while (task->content != NULL)
	{
		delete_env_var(env, task->content);
		task = task->next;
	}
}