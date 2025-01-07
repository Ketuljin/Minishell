/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:32:57 by vdunatte          #+#    #+#             */
/*   Updated: 2025/01/08 00:04:36 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

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

void	stock_2mlc(char **remaining_str, char *str)
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
	free(str);
}