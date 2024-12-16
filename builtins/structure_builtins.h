/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_minishell.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:45 by jkerthe           #+#    #+#             */
/*   Updated: 2024/12/10 16:25:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_MINISHELL_H
# define STRUCTURE_MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_command
{
	struct s_command	*next;
	struct s_task		*first;
	char		*full_task;
	int			out_put;
	int			in_put;
}			t_command;

typedef struct s_task
{
	struct s_task	*next;
	struct s_task	*prev;
	char	*content;
	int		type;

}		t_task;

/* ************************************************************************** */
int		ft_exec_cd(t_command *command, char **env);
char	*option_cd(char	*content, char **env);
int		execute_cd_args(t_command *command, char **env);
int		cd_no_arg(char **env);
char    **change_var(char **env, char *new_value, char *name);
/* ************************************************************************** */
int		ft_exec_echo(t_command *command);
int		option_echo(char *a);
/* ************************************************************************** */
int		ft_exec_env(t_command *command, char **env);
char	*get_env_var(const char *var, char **env);
int		create_env_var(char **env, char *str);
/* ************************************************************************** */
char **	exec_export(t_command *command, char **env);
int	check_task(char	*str);
char**	add_env_var(char **env, char *str);
/* ************************************************************************** */
int	export_no_arg(t_command *command, char **env);
void	printf_export(char **stock, t_command *command);
void	ascii_order(char **stock, t_command *command);
int	order_check(char	**stock);
int	compare_ascii(char *s1, char *s2);
/* ************************************************************************** */
int		ft_exec_pwd(char	**env);
/* ************************************************************************** */
int		count_line(char	**str);
void	free_double(char **str);
int		count_task(t_command *command);
char **copy_memory(char **src, char **dest, int z);

#endif
