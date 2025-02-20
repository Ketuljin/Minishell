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
#include "../builtins/structure_builtins.h"

volatile sig_atomic_t	g_status = 0;

int	ft_execvp(t_command *command)
{
	t_task	*task;
	char	*args[256];
	int		i;

	i = 0;
	task = command->first;
	while (task && i < 255)
	{
		args[i++] = task->content;
		task = task->next;
	}
	args[i] = NULL;
	execvp(args[0], args);
	perror("execvp failed");
	exit(1);
}

int	ft_exec_parent(int **pipes, int nb_command)
{
	int	i;
	int	status;

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

int	ft_create_process(int **pipes, t_command *command, char ***env,
						int count)
{
	pid_t	pid;
	int		nb_command;

	nb_command = count_task(command);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		if (count > 0)
			dup2(pipes[count -1][0], command->in_put);
		if (count < nb_command -1)
			dup2(pipes[count][1], command->out_put);
		close_pipes(pipes, nb_command);
		command = search_command(command, count);
		if (is_builtin(command->first->content))
			exit(exec_builtin(command, env));
		else
			exit(ft_execvp(command));
	}
	return (0);
}

int	ft_check(t_command *command, char ***env)
{
	int	nb_command;

	nb_command = count_task(command);
	if (nb_command == 0)
		return (0);
	else if (nb_command == 1)
	{
		if (is_builtin(command->first->content))
			return (exec_builtin(command, env));
		else
			return (ft_execvp(command));
	}
	else
		return (ft_exec_pipe(command, env, nb_command));
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp) {
    (void)argc;
    (void)argv;
    
    t_task *task = malloc(sizeof(t_task));
    task->content = strdup("ls");
    task->next = NULL;
    task->prev = NULL;
    task->type = 0;
/*
	t_task *sec_task =  malloc(sizeof(t_task));
	task->next = sec_task;
    sec_task->content = strdup("truc");
    sec_task->next = NULL;
    sec_task->prev = task;
    sec_task->type = 0;

	t_task *third_task =  malloc(sizeof(t_task));
	sec_task->next = third_task;
    third_task->content = strdup("truc");
    third_task->next = NULL;
    third_task->prev = sec_task;
    third_task->type = 0;


    t_command *command = malloc(sizeof(t_command));
    command->first = task;
    command->full_task = strdup("ls");
    command->out_put = STDOUT_FILENO;
    command->in_put = STDIN_FILENO;
    command->next = NULL;

	t_task *big =  malloc(sizeof(t_task));
    big->content = strdup("grep");
    big->next = NULL;
    big->prev = NULL;
    big->type = 0;

	t_task *big_t =  malloc(sizeof(t_task));
	big->next = big_t;
    big_t->content = strdup(".c");
    big_t->next = NULL;
    big_t->prev = big;
    big_t->type = 0;

	t_command *sec_command = malloc(sizeof(t_command));
    command->next = sec_command ;
	sec_command->first = big;
    sec_command->full_task = strdup("cat");
    sec_command->out_put = STDOUT_FILENO;
    sec_command->in_put = STDIN_FILENO;
    sec_command->next = NULL;

    int result = ft_check(command, &envp);
    printf("Résultat de ft_check: %d\n", result);

    free(task->content);
    free(task);
    free(command->full_task);
    free(command);
    
    return 0;
}
	*/