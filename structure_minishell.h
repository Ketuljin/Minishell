/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_minishell.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:45 by jkerthe           #+#    #+#             */
/*   Updated: 2025/02/27 17:37:04 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_MINISHELL_H
# define STRUCTURE_MINISHELL_H

typedef struct s_command
{
	struct s_command	*next;
	struct s_task		*first;
	char				*full_task;
	int					fd_in_put;
	int					fd_out_put;
}			t_command;

typedef struct s_task
{
	struct s_task	*next;
	char			*content;
	int				type;
}		t_task;

#endif
