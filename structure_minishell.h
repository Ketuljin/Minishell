/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_minishell.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:45 by jkerthe           #+#    #+#             */
/*   Updated: 2024/11/28 15:52:21 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_MINISHELL_H
# define STRUCTURE_MINISHELL_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef s_command
{
	s_command	*next;
	s_task		*first;
	char		*full_task;
	int			out_put;
	int			in_put;
}			t_command;

typedef s_task
{
	s_task	*next;
	s_task	*prev;
	char	*content;
	int		type;

}		t_task;

#endif
