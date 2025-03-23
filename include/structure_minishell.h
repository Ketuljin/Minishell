/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_minishell.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:45 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/23 01:45:40 by vdunatte         ###   ########.fr       */
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
	pid_t				pid;
}			t_command;

typedef struct s_task
{
	struct s_task	*next;
	char			*content;
	int				type;
}		t_task;

typedef struct s_env_ex
{
	char	**env;
	int		exit_code;
}		t_env_ex;

#endif
