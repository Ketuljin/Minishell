/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:30:20 by vdunatte          #+#    #+#             */
/*   Updated: 2024/12/05 21:33:22 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newlibft/libft.h"
# include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char const **argv, char **envp)
{
	char	**environment;
	// char	*test;

	(void)argv;
	(void)argc;
	environment = ft_tabdup(envp);
	// test = readline("torture : ");
	ft_tabfree(environment);
	return 0;
}