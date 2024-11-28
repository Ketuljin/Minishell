#include "structure_minishell.h"

static void	change_pwd(char **env, char *new_path)
{
	int 	i;
	char	*current_pwd;

	i = 0;
	if (!env || !new_path)
		return ;
	while(env[i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
		{
			current_pwd = env[i] + 4;
			ft_strcpy(current_pwd, new_path);
			return ;
		}
		i++;
	}
}
static void	change_oldpwd(char **env, char *new_path)
{
	int 	i;
	char	*current_pwd;

	i = 0;
	if (!env || !new_path)
		return ;
	while(env[i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			current_pwd = env[i] + 4;
			ft_strcpy(current_pwd, new_path);
			return ;
		}
		i++;
	}
}

char *get_env_var(const char *var, char **env) {
    int len;
	int	i;

	if (!var || !env)
		return NULL;
	len = ft_strlen(var);
	i = 0;
  	while(env[i]) {
        if (ft_strncmp(env[i], var, len) == 0 && env[i][len] == '=')
            return (env[i] + len + 1);
		i++;
    }
    return NULL;
}





int	execute_cd_args(t_command *command, char *current_path, char **env)
{

	t_task task = command->task->next;

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