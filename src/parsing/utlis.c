/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:02:08 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/15 04:21:44 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	skip_quote(char **temp)
{
	if ((*temp)[0] == '\"' || (*temp)[0] == '\'')
	{
		(*temp) = ft_strchr((*temp) + 1, (*temp)[0]);
		if ((*temp) == NULL)
			return (1);
	}
	return (0);
}

char	*extract_skip(char **line, int len)
{
	char	*ret;

	ret = ft_substr(*line, 0, len);
	if (ret == NULL)
		return (NULL);
	*line += len;
	return (ret);
}

int	char_count(char *s, char c, char d)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (s[0] == c || s[0] == d)
			i++;
		s++;
	}
	return (i);
}

int	print_error(char *msg_error, t_env_ex **env_ex, int exit_code)
{
	(*env_ex)->exit_code = exit_code;
	if (msg_error != NULL)
		write(STDERR_FILENO, msg_error, ft_strlen(msg_error));
	return (1);
}
