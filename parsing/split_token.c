/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:56:44 by vdunatte          #+#    #+#             */
/*   Updated: 2025/02/08 01:35:19 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_task	*lst_task_new(void *content, t_task prev)
{
	t_task	*lst;

	lst = malloc(sizeof(t_task));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	lst->prev = prev;
	lst->type = 0;
	return (lst);
}

int	split_token(t_command *first)
{
	
}