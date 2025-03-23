/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_execute.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:45 by jkerthe           #+#    #+#             */
/*   Updated: 2025/03/23 07:15:49 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_EXECUTE_H
# define STRUCTURE_EXECUTE_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include "structure_minishell.h"
# include "minishell.h"
# include "../newlibft/libft.h"

# define WRITE 1
# define READ 0

void			ft_exec_exit(t_command *command, t_env_ex *env,
					t_command *first_command, int saved_stdout);
int				ft_exec_echo(t_command *command, t_task *task);
int				safe_write(char *content, int fd);
int				ft_exec_export(t_command *command, char ***env, t_task *task);
int				ft_exec_unset(t_task *task, char ***env);
int				ft_exec_pwd(char	**env);
int				ft_exec_env(t_command *command, char **env);
int				ft_exec_cd(t_task *task, char ***env);
char			*get_env_var(const char *var, char **env);
char			**change_pwd(char ***env, char *new_value, char *name);
char			**change_var(char ***env, char *new_value, char *name);
int				count_task(t_task *task);
char			**add_env_var(char **env, char *str);
void			free_double(char **str);
int				count_line(char	**str);
int				count_command(t_command *command);
char			**copy_memory(char **src, char **dest, int z);
int				export_no_arg(t_command *command, char **env);
void			ft_execute(t_command *command, t_env_ex *env);
t_task			*check_first(t_command *command);
int				is_builtin(t_command *command);
void			ft_verif_in_put(t_command *command);
void			ft_close_out_put(t_command *command, int fd_save);
int				ft_open_out_put(t_type type, int out_put,
					char *content, int saved_stdout);
void			ft_verif_out_put(t_command *command);
int				ft_exec_pipe(t_command *command, int nb_command, t_env_ex *env);
int				is_pipe(t_command *command);
void			ft_close(int *fd);
t_command		*search_command(t_command *command, int count);
int				ft_create_process(int lastfd, int pfd[2], int i, t_env_ex *env);
int				ft_exec_parent(t_command *command);
int				exec_builtin(t_command *command, t_env_ex *env,
					t_command *first_command);
bool			handle_redir(t_command *cmd, bool in, bool out);
void			print_exec_err(int type, char *str, int errsv);
int				try_execve(t_command *command, t_env_ex *env);
char			last_content(char *str);
t_task			*first_task(t_command *command);
int				no_path(char *content);
void			clean_all(char **args, t_env_ex *env_ex, t_command **command);
int				create_path(t_task *task, char **path, t_env_ex *env_ex);
char			*valid_command(char *content, char **stock);
int				count_slash(char *content);
void			copy_slash(char *content, char *stock);
char			*delete_sl(char	*content);
long long int	ft_atoie(const char	*nptr);
int				size_comp(char *content, char *env);
int				check_sign(char c);

#endif
