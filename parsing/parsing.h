/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:53:14 by vdunatte          #+#    #+#             */
/*   Updated: 2025/01/08 02:07:36 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>

# include "../newlibft/libft.h"
# include "../structure_minishell.h"

int		parsing(char *line, char **envp, t_command *first, int value_return);

char	*replace_var(char *line, char **envp, int value_return);

#endif