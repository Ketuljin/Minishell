/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:04:13 by jkerthe           #+#    #+#             */
/*   Updated: 2024/12/16 18:36:47 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_execute.h"

char    last_content(char *str)
{
    if (!str) 
        return '\0'; 
    return (str[ft_strlen(str) -1]);
}

char    *valid_command(char *content, char **stock)
{
    char    *full_command;
    int        fd;
    int        i;

    i = 0;
    fd = -1;
    while (stock[i]) 
    {
        full_command = malloc(ft_strlen(stock[i]) + ft_strlen(content) + 2);
        if (!full_command) 
            return (NULL);
        ft_strlcpy(full_command, stock[i], ft_strlen(stock[i]) + 1);
        if (last_content(stock[i]) != '/')
            ft_strlcat(full_command, "/", ft_strlen(full_command) + 2);
        ft_strlcat(full_command, content, ft_strlen(full_command) + ft_strlen(content) + 1);
        fd = open(full_command, O_RDONLY);
        if (fd != -1)
            return (full_command);
        free(full_command);
        i++;
    }
    return (NULL);
}
char    *search_path(char *content, char **env)
{
    char    *path;
    char    **stock;
    char    *full_path;

    path = get_env_var("PATH", env);
    if (path == NULL)
        return (NULL);
    stock = ft_split(path, ':');
    full_path = valid_command(content, stock);
    free_double(stock);
    return (full_path);
}

t_task	*first_task(t_command *command)
{
	t_task *actual_task;

	actual_task = command->first;
	while (actual_task)
	{
		if (actual_task->type == 0)
			return(actual_task);
		actual_task = actual_task->next;
	}
	return (NULL);
}

int	no_path(char *content)
{
	int i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '/')
			return (0);
		i++;
	}
	return (1);
}

int    ft_execve(t_command *command, t_env_ex *env_ex)
{
    t_task    *task;
    char    **args;
    int        i;
    char    *path;
	int		saved_stdin;
	int		saved_stdout;

    i = 1;
	task = first_task(command);
	if (task == NULL)
		return (1);
	if (!no_path(task->content))
		path = ft_strdup(task->content);
	else
		path = search_path(task->content, env_ex->env);
	if (path == NULL)
		return (1);
	saved_stdout = ft_verif_out_put(command);
    saved_stdin = ft_verif_in_put(command);
    args = malloc(sizeof(char*) * (count_task(command->first) + 1));
    args[0] = ft_strdup(task->content);
    task = task->next;
    while (task != NULL)
    {
		if (task->type == 0)
        	args[i] = ft_strdup(task->content);
        task = task->next;
        i++;
    }
    args[i] = NULL;
	
    if (execve(path, args, env_ex->env) == -1)
    {
        perror("execve");
        free_double(args);
        ft_tabfree(env_ex->env);
        free(env_ex);
        free_struct(&command);
		ft_close_out_put(command, saved_stdout);
		ft_close_in_put(command, saved_stdin);
        rl_clear_history();
    }
    return (0);
}

int	ft_exec_parent(int **pipes, int nb_command)
{
	int	i;
	int	status;
	int	g_status;

	i = 0;
	close_pipes(pipes, nb_command);
	while (i < nb_command)
	{
		wait(&status);
		i++;
	}
	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		g_status = WTERMSIG(status);
		if (g_status != 131)
			g_status += 128;
	}
	free_pipe(pipes, nb_command);
	return (g_status);
}

int	ft_create_process(int **pipes, t_command *command, t_env_ex *env,
						int count)
{
	pid_t	pid;
	int		nb_command;
	int		ex;
	t_command	*first_command;

	ex = 0;
	nb_command = count_command(command);
	first_command = command;
	command = search_command(command, count);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		if (count > 0)
			dup2(pipes[count -1][0], STDIN_FILENO);
		if (count < nb_command -1)
			dup2(pipes[count][1], STDOUT_FILENO);
		close_pipes(pipes, nb_command);
		if (!is_builtin(command->first->content))
		{
			exec_builtin(first_command, env);
			ft_tabfree(env->env);
			free(env);
			free_struct(&first_command);
			rl_clear_history();
			free_pipe(pipes, nb_command);
			exit (ex);
		}
		else
		{
			ft_execve(first_command, env);
			ft_tabfree(env->env);
			free(env);
			free_struct(&first_command);
			rl_clear_history();
			free_pipe(pipes, nb_command);
			exit (ex);
		}
	}
	return (0);
}

void	create_save_pwd(char ***env)
{
	char	*stock;
	char	*path;

	path = NULL;
	stock = get_env_var("-P_W_D", *env);
	if (stock == NULL)
	{
		path = malloc(sizeof(char ) * 1000);
		getcwd(path, 1000);
		change_var(env, path, "-P_W_D");
		free(path);
	}
}

void	ft_execute(t_command *command, t_env_ex *env)
{
	int	nb_command;
	t_task	*task;

	create_save_pwd(&env->env);
	nb_command = count_command(command);
	
	if (nb_command == 0)
		return ;
	task = check_first(command);
	if (nb_command == 1 && !is_builtin(task->content))
	{
		if (!ft_strncmp("exit", command->first->content, ft_strlen(command->first->content)))
			ft_exec_exit(command, env);
		env->exit_code = exec_builtin(command, env);
	}
	else
		env->exit_code = ft_exec_pipe(command, env, nb_command);
}