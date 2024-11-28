#include "structure_minishell.h"

int	count_task(t_command *command)
{
	t_task *actual_task = command->task;
	int i = 1;

	while(actual_task->next)
	{
		i++;
		actual_task = actual_task->next;
	}
	return(i);
}