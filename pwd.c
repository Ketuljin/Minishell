#include "structure_minishell.h"

void	ft_exec_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	if (path)
	{
		free (path);
		path = NULL;
	}
	return (0);
}
