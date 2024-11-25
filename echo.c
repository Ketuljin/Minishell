#include "structure_minishell.h"

int	option(char *a)
{
	if(*a != '-')
		return(0);
	a++;
	if(!*a)
		return (0);
	while(*a)
	{
		if (*a != 'n')
			return(0);
		a++;
	}
	return(1);

}

int ft_exec_echo(t_command *command)
{
	t_task * task = command->first->next;
	int	suppress_newline = 0;
	int	first_arg = 1;

	if (tast && option(task->content))
	{
		suppress_newline = 1;
		task = task->next;
	}
	while (task)
	{
		if (!first_arg)
			printf(" ");
		printf("%s", task->content);
		first_arg = 0;
		task = task->next;
	}
	if (!suppress_newline)
		printf("\n");
	return (1);
}