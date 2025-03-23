/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_minishell.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:45 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/23 07:16:33 by vdunatte         ###   ########.fr       */
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

// 1 : > :redirige la sortie
// 2 : < :redirige l'entree
// 3 : >> :redirige la sortie et garde le contenu
// 4 : << :recupere avec readline
typedef enum e_type
{
	T_CMD = 0,
	R_OUT, // 1
	R_IN, //  2
	R_APP, // 3
	R_HD, //  4
}	t_type;

typedef struct s_task
{
	struct s_task	*next;
	char			*content;
	t_type			type;
}		t_task;

typedef struct s_env_ex
{
	char		**env;
	int			exit_code;
	t_command	*cmd;
}		t_env_ex;

#endif
