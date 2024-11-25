#include "structure_minishell.h"

void	ft_exec_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	printf("%s\n", path);
	if (path)
	{
		free (path);
		path = NULL;
	}
	return (0);
}
