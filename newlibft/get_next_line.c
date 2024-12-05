/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:08:06 by vdunatte          #+#    #+#             */
/*   Updated: 2024/08/19 01:37:57 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

char	*destock(char **remaining_str, unsigned int i)
{
	char	*s;
	char	*temp;

	if (*remaining_str == NULL)
		return (NULL);
	if (i > (unsigned int)ft_strlen(*remaining_str))
		i = ft_strlen(*remaining_str);
	s = ft_strdup (*remaining_str);
	free(*remaining_str);
	if (s == NULL)
		return (NULL);
	*remaining_str = ft_substr(s, i, ft_strlen(s) - i);
	if (*remaining_str == NULL)
		return (NULL);
	temp = ft_substr(s, 0, i);
	free(s);
	return (temp);
}

void	stock(char **remaining_str, char *str)
{
	char	*s;

	s = NULL;
	if (*remaining_str != NULL)
	{
		s = ft_strdup (*remaining_str);
		free(*remaining_str);
	}
	if (s == NULL || str == NULL )
	{
		if (s == NULL && str == NULL)
			*remaining_str = ft_strjoin("", "");
		if (s == NULL && str != NULL)
			*remaining_str = ft_strjoin("", str);
		if (s != NULL && str == NULL)
			*remaining_str = ft_strjoin(s, "");
	}
	else
		*remaining_str = ft_strjoin(s, str);
	if (*remaining_str != NULL)
		free(s);
}

char	*get_last_line(int fd, char **remaining_str, int nbread)
{
	if (nbread != BUFFER_SIZE)
	{
		if (nbread == 0 && *remaining_str[0] == '\0')
		{
			free(*remaining_str);
			*remaining_str = NULL;
			return (NULL);
		}
		if (ft_strchr(*remaining_str, '\n') == NULL
			&& *remaining_str != NULL
			&& *remaining_str[0] != '\0')
			return (destock(remaining_str, ft_strlen(*remaining_str)));
	}
	return (get_next_line(fd));
}

char	*read_error(char *str, char *remaining_str)
{
	free(str);
	if (remaining_str != NULL)
		remaining_str[0] = '\0';
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*str;
	int			i;
	static char	*remaining_str = NULL;
	int			nbread;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	i = 0;
	if (remaining_str != NULL)
	{
		if (ft_strchr(remaining_str, '\n') != NULL)
		{
			i = (long)ft_strchr(remaining_str, '\n') - (long)remaining_str;
			return (destock(&remaining_str, i + 1));
		}
	}
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	nbread = read(fd, str, BUFFER_SIZE);
	if (nbread == -1)
		return (read_error(str, remaining_str));
	str[nbread] = '\0';
	stock(&remaining_str, str);
	free(str);
	return (get_last_line(fd, &remaining_str, nbread));
}

// int	main(void)
// {
// 	int	fd;
//
// 	fd = open("oups", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return (1);
// }
