/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_execute.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:45 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/14 04:55:43 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_EXECUTE_H
# define STRUCTURE_EXECUTE_H

# include "structure_minishell.h"
# include "minishell.h"
# include "../newlibft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>

/* ******************** cd.c ******************** */
int			cd_no_arg(char ***env);
int			execute_cd_args(t_command *command, char ***env);
char		*option_cd(char *content, char **env);
int			ft_exec_cd(t_command *command, char ***env);
/* ******************** echo.c ******************** */
int			option_echo(char *a);
int			ft_exec_echo(t_command *command);
/* ******************** env.c ******************** */
char		*get_env_var(const char *var, char **env);
int			ft_exec_env(t_command *command, char **env);
/* ******************** export_print.c ******************** */
int			compare_ascii(char *s1, char *s2);
int			order_check(char	**stock);
void		ascii_order(char **stock, t_command *command);
void		printf_export(char **stock, t_command *command);
int			export_no_arg(t_command *command, char **env);
/* ******************** export.c ******************** */
char		**add_env_var(char **env, char *str);
int			check_task(char	*str);
int			arleady_exist(char **env, char *content);
int			export_arg(char ***env, char *content);
int			ft_exec_export(t_command *command, char ***env);
/* ******************** pwd.c ******************** */
int			ft_exec_pwd(char **env);
/* ******************** unset.c ******************** */
char		**delete_env_line(char **env, int pos);
char		**delete_env_var(char **env, char *str);
int			ft_exec_unset(t_command *command, char ***env);
/* ******************** utils_task.c ******************** */
void		free_double(char **str);
int			count_line(char	**str);
int			count_task(t_command *command);
char		**copy_memory(char **src, char **dest, int z);
int			count_command(t_command *command);
/* ******************** ft_exec.c ******************** */
int			ft_execvp(t_command *command, char ***env);
int			ft_exec_parent(int **pipes, int nb_command);
int			ft_create_process(int **pipes, t_command *command, t_env_ex *env,
				int count);
void		ft_execute(t_command *command, t_env_ex *env);
/* ******************** check_builtin.c ******************** */
int			is_builtin(char *content);
int			exec_builtin(t_command *command, t_env_ex *env);
t_command	*search_command(t_command *command, int count);
int			count_out_put(t_command *command);
/* ******************** change_var.c ******************** */
char		*change_var_utils(char *name, char *newvalue, int name_len);
char		**change_var(char ***env, char *new_value, char *name);
char		**change_pwd(char ***env, char *new_value, char *name);
/* ******************** pipes_utils.c ******************** */
void		close_pipes(int **pipes, int nb_command);
int			**ft_create_pipe(int nb_command);
int			**free_pipe(int **pipes, int nb_command);
int			ft_exec_pipe(t_command *command, t_env_ex *env, int nb_command);
int			is_pipe(t_command *command);
char		*path_execve(const char *dir, const char *command);
void		ft_close_dup(t_command *command, int fd);
int			ft_open_out_put(int type, int out_put,
				char *content, int saved_stdout);
int			ft_verif_out_put(t_command *command);
void		ft_close_out_put(t_command *command, int fd_save);
int			ft_verif_in_put(t_command *command);
int			ft_open_in_put(int type, int in_put,
				char *content, int saved_stdin);
void		open_str_stdin(const char *str);
void		ft_close_in_put(t_command *command, int fd_stdin);
void		ft_exec_exit(t_command *command, t_env_ex *env);

#endif
