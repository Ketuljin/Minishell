/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_builtins.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:47:45 by jkerthe           #+#    #+#             */
/*   Updated: 2025/02/20 10:43:45 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_BUILTINS_H
# define STRUCTURE_BUILTINS_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/wait.h>

typedef struct s_command
{
	struct s_command	*next;
	struct s_task		*first;
	char				*full_task;
	int					out_put;
	int					in_put;
}			t_command;

typedef struct s_task
{
	struct s_task	*next;
	struct s_task	*prev;
	char			*content;
	int				type;

}		t_task;

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
int			ft_exec_pwd(t_command *command);
/* ******************** unset.c ******************** */
char		**delete_env_line(char **env, int pos);
char		**delete_env_var(char **env, char *str);
int			ft_exec_unset(t_command *command, char ***env);
/* ******************** utils_task.c ******************** */
void		free_double(char **str);
int			count_line(char	**str);
int			count_task(t_command *command);
char		**copy_memory(char **src, char **dest, int z);
/* ******************** ft_exec.c ******************** */
int			ft_execvp(t_command *command);
int			ft_exec_parent(int **pipes, int nb_command);
int			ft_create_process(int **pipes, t_command *command,
				char ***env, int count);
int			ft_check(t_command *command, char ***env);
/* ******************** check_builtin.c ******************** */
int			is_builtin(char *content);
int			exec_builtin(t_command *command, char ***env);
t_command	*search_command(t_command *command, int count);
/* ******************** change_var.c ******************** */
char		*change_var_utils(char *name, char *newvalue, int name_len);
char		**change_var(char ***env, char *new_value, char *name);
char		**change_pwd(char ***env, char *new_value, char *name);
/* ******************** pipes_utils.c ******************** */
void		close_pipes(int **pipes, int nb_command);
int			**ft_create_pipe(int nb_command);
int			**free_pipe(int **pipes, int nb_command);
int			ft_exec_pipe(t_command *command, char ***env, int nb_command);
int			is_pipe(t_command *command);

#endif
