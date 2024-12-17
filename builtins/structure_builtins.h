/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_builtins.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:45 by jkerthe           #+#    #+#             */
/*   Updated: 2024/12/17 15:34:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_BUILTINS_H
# define STRUCTURE_BUILTINS_H

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
int		ft_exec_cd(t_command *command, char ***env);
char	*option_cd(char *content, char **env);
int		execute_cd_args(t_command *command, char ***env);
int		cd_no_arg(char ***env);
char    **change_var(char ***env, char *new_value, char *name);
/* ************************************************************************** */
void	ft_exec_echo(t_command *command);
int	option_echo(char *a);
/* ************************************************************************** */
int	ft_exec_env(t_command *command, char **env);
char	*get_env_var(const char *var, char **env);
/* ************************************************************************** */
int	export_no_arg(t_command *command, char **env);
void	printf_export(char **stock, t_command *command);
void	ascii_order(char **stock, t_command *command);
int	order_check(char	**stock);
int	compare_ascii(char *s1, char *s2);
/* ************************************************************************** */
char	**ft_exec_export(t_command *command, char **env);
char	**export_arg(char **env, char *content);
int	arleady_exist(char **env, char *content);
int	check_task(char	*str);
char**	add_env_var(char **env, char *str);
/* ************************************************************************** */
void	ft_exec_pwd(t_command *command, char	**env);
/* ************************************************************************** */
char	**ft_exec_unset(t_command *command, char **env);
char	**delete_env_var(char **env, char *str);
char	**delete_env_line(char **env, int pos);
/* ************************************************************************** */
char	**copy_memory(char **src, char **dest, int z);
int	count_task(t_command *command);
int	count_line(char	**str);
void	free_double(char **str);
/* ************************************************************************** */


#endif
