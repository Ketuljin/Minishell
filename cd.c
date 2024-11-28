#include "structure_minishell.h"

static void	change_pwd(char **env, char *new_path)//to do
{
	
}







int	execute_cd_args(t_command *command, char *current_path, char **env)
{
	//char	*next_pwd;

	t_task task = command->task->next;
	//new_pwd = NULL;
	if (task != NULL)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (0);
	}
	if (chdir(task) == -1)
	{
		ft_putstr_fd("minishell: cd:", 2);
		ft_putstr_fd(command->task->next->content, 2);
		ft_putstr_fd(": no such file or directory", 2);
		return (0);
	}
	return (1);
}

int	cd_no_arg(t_command *command, char **env)
{
	char	*home;

	home = get_env_var("HOME");
	if (!home)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return 0;
	}
	if(chdir(home) == -1)
	{
		ft_putstr_fd("message d'erreur à definir", 2);
		return (0);
	}
	return (1);
}



int ft_exec_cd(t_command *command, char **env)
{
	int		i;
	char	*current_path;

	i = 0;
	current_path = getcwd(NULL, 0);
	if (!current_path)
	{
		ft_putstr_fd("minishell: getcwd", 2);
		return 0;
	}
	i = count_task(command);
	if (i > 2)
	{
		ft_putstr_fd("-Minishell: cd: too many arguments", 2);
		free(current_path);
		return(1);
	}
	if (i == 1)
		cd_no_arg(command, env);
	else if (i == 2)
		cd_args(command, current_path, env);
	free(current_path);
	return(0);
}