/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_execute.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:45 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/14 16:31:32 by jkerthe          ###   ########.fr       */
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
# include <errno.h>

int		ft_exec_echo(t_command *command, t_task *task);
int		safe_write (char *content, int fd);
int		ft_exec_export(t_command *command, char ***env, t_task *task);
int		ft_exec_unset(t_task *task, char ***env);
int		ft_exec_pwd(char	**env);
int		ft_exec_env(t_command *command, char **env);
int		ft_exec_cd(t_task *task, char ***env);
char	*get_env_var(const char *var, char **env);
char	**change_pwd(char ***env, char *new_value, char *name);
char	**change_var(char ***env, char *new_value, char *name);
int		count_task(t_task *task);
char	**add_env_var(char **env, char *str);
void	free_double(char **str);
int		count_line(char	**str);
int		count_command(t_command *command);
char	**copy_memory(char **src, char **dest, int z);
int		export_no_arg(t_command *command, char **env);
void	ft_execute(t_command *command, t_env_ex *env);
t_task	*check_first(t_command *command);
int		is_builtin(char	*content);
void	ft_exec_exit(t_command *command, t_env_ex *env);
int		exec_builtin(t_command *command, t_env_ex *env);
int		ft_verif_in_put(t_command *command);
void	ft_close_in_put(t_command *command, int fd_stdin);
void	ft_close_out_put(t_command *command, int fd_save);
int			ft_open_out_put(int type, int out_put,
		char *content, int saved_stdout);
int		ft_verif_out_put(t_command *command);
int		ft_exec_pipe(t_command *command, t_env_ex *env, int nb_command);
int		is_pipe(t_command *command);
int		**free_pipe(int **pipes, int nb_command);
int			**ft_create_pipe(int nb_command);
void		close_pipes(int **pipes, int nb_command);
t_command	*search_command(t_command *command, int count);
int	ft_create_process(int **pipes, t_command *command, t_env_ex *env,
						int count);
int	ft_exec_parent(int **pipes, int nb_command);
#endif
