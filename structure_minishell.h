/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_minishell.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:45 by jkerthe           #+#    #+#             */
/*   Updated: 2024/12/13 20:59:23 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_MINISHELL_H
# define STRUCTURE_MINISHELL_H

typedef struct s_command
{
	struct s_command	*next;
	struct s_task		*first;
	char				*full_task;
	int					out_put;
	int					in_put;
}			t_command;

typedef struct s_task
{
	struct s_task	*next;
	struct s_task	*prev;
	char			*content;
	int				type;

}		t_task;

#endif
