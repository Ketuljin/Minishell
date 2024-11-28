#include "structure_minishell.h"

int	option(char *a)
{
	if(*a != '-')
		return(1);
	a++;
	if(!*a)
		return (1);
	while(*a)
	{
		if (*a != 'n')
			return(1);
		a++;
	}
	return(0);

}

int ft_exec_echo(t_command *command)
{
	t_task *task = command->first->next;
	int	suppress_newline = 0;
	int	first_arg = 1;

	if (task && !option(task->content))
	{
		suppress_newline = 1;
		task = task->next;
	}
	while (task)
	{
		if (!first_arg)
			ft_putstr_fd(" ", 1);
		ft_putstr_fd(task->content, 1);
		first_arg = 0;
		task = task->next;
	}
	if (!suppress_newline)
		ft_putstr_fd("\n", 1);
	return (0);
}