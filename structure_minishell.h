/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_minishell.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:45 by jkerthe           #+#    #+#             */
/*   Updated: 2024/12/05 15:44:33 by jkerthe          ###   ########.fr       */
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

/* ************************************************************************** */
char	*option(char	*content);
int		execute_cd_args(t_command *command, char *current_path, char **env);
int		cd_no_arg(t_command *command, char **env);
int		ft_exec_cd(t_command *command, char **env);
/* ************************************************************************** */
int		option(char *a);
int		ft_exec_echo(t_command *command);
/* ************************************************************************** */
int		ft_exec_env(t_command *command, char **env);
char	*get_env_var(const char *var, char **env);
int		create_env_var(char **env, char *str);
/* ************************************************************************** */
int		exec_export(t_command *command, char **env);
int		check_task(char	*str);
int		export_no_arg(t_command *command, char **env);
void	ascii_order(char **stock, t_command *command);
int		order_check(char	**stock);
/* ************************************************************************** */
int		ft_exec_pwd(char	**env);
/* ************************************************************************** */

#endif
