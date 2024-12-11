#include "minishell.h"

void	free_struct2(t_task	*first)
{
	if (first == NULL)
		return ();
	free_struct2(first->next);
	free(first->content);
	first->content = NULL;
	first->prev = NULL;
	free(first);
	first = NULL;
}

void	free_struct(t_command	*first)
{
	if (first == NULL)
		return ();
	free_struct(first->next);
	free(first->full_task);
	first->full_task = NULL;
	free_struct2(first->first);
	free(first);
	first = NULL;
}