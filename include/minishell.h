/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:38:37 by vdunatte          #+#    #+#             */
/*   Updated: 2024/12/13 20:38:37 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>

# include "parsing.h"
# include "../newlibft/libft.h"
# include "structure_execute.h"
# include "structure_minishell.h"

typedef enum e_setsig
{
	S_INTERACTIVE,
	S_HEREDOC,
	S_IGNORE,
	S_DEFAULT,
}	t_setsig;

void	free_struct(t_command **first);

extern int		g_last_sig;
void	set_signals(t_setsig set);

#endif
