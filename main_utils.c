/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:38:28 by vdunatte          #+#    #+#             */
/*   Updated: 2024/12/13 20:38:28 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_struct2(t_task	**first)
{
	if (*first == NULL)
		return ;
	if ((*first)->next != NULL)
		free_struct2(&(*first)->next);
	free((*first)->content);
	(*first)->content = NULL;
	free(*first);
	*first = NULL;
}

void	free_struct(t_command	**first)
{
	if (*first == NULL)
		return ;
	if ((*first)->next != NULL)
		free_struct(&(*first)->next);
	free((*first)->full_task);
	(*first)->full_task = NULL;
	free_struct2(&(*first)->first);
	free(*first);
	*first = NULL;
}
