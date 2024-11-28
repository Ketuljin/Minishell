/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:38:04 by jkerthe           #+#    #+#             */
/*   Updated: 2024/11/20 17:59:27 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "get_next_line.h"

static int		test = 0;
void    finish(int signum) //gestion de ctrl +D
{
    write(1, "\n", 1);
    exit(EXIT_FAILURE);
}
void	sigint_handler(int signum) //gestion de ctrl + C
{
    write(1, "\n", 1);
	write(1, "$>", 2);
}

static  int write_path(char *path)
{
    int i = 0;
    while(path[i])
    {
        write(1, &path[i], 1);
        i++;
    }
    write(1, ": ", 2);
    return(i);
}

int	main()
{
	char	*buffer = NULL;
	size_t	buf_size = 2048;
    char    *path = NULL;
    
    (void) signal(SIGINT, sigint_handler);
    (void) signal(SIGSEGV, finish);
    
    path = malloc(sizeof(char) * buf_size);
	if (path == NULL) {
		perror("Malloc failure");
		return (EXIT_FAILURE);
	}
    if (getcwd(path, buf_size) == NULL) {
        perror("getcwd failure");
        free(path);
        return EXIT_FAILURE;
    }
    write_path(path);
	while (test != 1) {
        getcwd(path, buf_size);
        buffer = get_next_line(0);
		if(buffer == NULL)
			break ;
		getcwd(path, buf_size);
        write_path(path);
        free(buffer);
	}
	free(path);
}