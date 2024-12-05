#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	order_check(char	**stock)
{
	int i;

	i = 0;
	while(stock[i] && stock[i+1])
	{
		if (strcmp(stock[i], stock[i+1]) > 0)
			return(1);
		i++;
	}
	return(0);
}

void	ascii_order(char **stock, t_command *command)
{
	char	*temp;
	int		i;

	temp = NULL;
	while (order_check(stock))
	{
		i = 0;
		while (stock[i] && stock[i+1])
		{
			if (strcmp(stock[i], stock[i+1]) > 0)
			{
				temp = stock[i];
				stock[i] = stock[i+1];
				stock[i+1] = temp;
			}
			i++;
		}
	}
	i = 0;
	while(stock[i])
	{
		ft_putstr_fd("declare -x ", command->out_put);
		ft_putstr_fd(stock[i], command->out_put);
		ft_putstr_fd("\n", command->out_put);
		i++;
	}

}

int	export_no_arg(t_command *command, char **env)
{
	char **stock;
	int count;
	int i;

	i = 0;
	count = 0;
	while(env[count] != NULL)
		count++;
	stock = malloc((count +1) * sizeof(char *));
	if (stock == NULL)
	{
		ft_putstr_fd("Erreur d'allocation mémoire", 2);
		return(1);
	}
	while (i < count)
	{
		stock[i] = env[i];
		i++;
	}
	stock[i] = NULL;
	ascii_order(stock, command);
	free(stock);
	return(0);
}

int	exec_export(t_command *command, char **env)
{
	t_task *task;

	task = command->first_task->next;
	if(task == NULL)
		export_no_arg(command, env);
	while(task != NULL)
	[
		if(check_task(task->content))
			create_export(task, env);
		task = task->next;
	]
}