int	is_builtin(char *content)
{
	int i;
	i = ft_strlen(content);
	if (ft_strncmp("echo", content, i))
		return (0);
	if (ft_strncmp("export", content, i))
		return (0);
	if (ft_strncmp("unset", content, i))
		return (0);
	if (ft_strncmp("pwd", content, i))
		return (0);
	if (ft_strncmp("env", content, i))
		return (0);
	if (ft_strncmp("cd", content, i))
		return (0);
	return (1);
}

char	**exec_builtin(t_command *command, char **env)
{
	t_task *task;

	task = command->first;
	if (ft_strncmp("echo", task->content, i))
		ft_exec_echo(command);
	if (ft_strncmp("export", task->content, i))
		env = ft_exec_export(command, env);
	if (ft_strncmp("unset", task->content, i))
		env = ft_exec_unset(command, env);
	if (ft_strncmp("pwd", task->content, i))
		ft_exec_pwd(command, env);
	if (ft_strncmp("env", task->content, i))
		env = ft_exec_env(command, env);
	if (ft_strncmp("cd", task->content, i))
		env = ft_exec_cd(command, env);
	return (env);
}

int	is_pipe(t_command *command)
{
	if (command->next !=  NULL)
		return (0)
	return (1);
}
