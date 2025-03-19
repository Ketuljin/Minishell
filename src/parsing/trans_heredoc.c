/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:32:37 by vdunatte          #+#    #+#             */
/*   Updated: 2025/03/19 18:40:13 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <readline/readline.h>

// 1 : > :redirige la sortie
// 2 : < :redirige l'entree
// 3 : >> :redirige la sortie et garde le contenu
// 4 : << :recupere avec readline

void	write_error_heredoc(char *eof)
{
	write(2, "torture: warning: here-document at line 42 delimited ", 54);
	write(2, "by end-of-file (wanted `", 25);
	write(2, eof, ft_strlen(eof));
	write(2, "')\n", 4);
}

int	take_herdoc(t_task **token)
{
	char	*line;
	int		i;

	i = 0; // faut que je cree un fichier temp
	
	while (1)
	{
		set_signals(S_HEREDOC);
		line = readline(">");
		set_signals(S_IGNORE);
		if (line == 0)
		{
			write_error_heredoc(&(*token)->content[2]);
			break ;
		}
		if (ft_strcmp(line, &(*token)->content[2]) == 0)
			break ;
		// if (i++ != 0)
			// met un \n dans le ficher
		// met line dans le ficher
	}
	return (0);
}

int for_d_enter(t_task **token)
{
	pid_t	pid;
	int		i;

	pid = fork();
	if (pid == -1)
		return (1);
	(*token)->type = 4;
	if (pid == 0)
	{
		take_herdoc(token);
		printf("Fils : Je suis le fils, mon pid interne est %d.\n", pid);
	}
	else if (pid > 0)
	{
		wait(&i);
		// reup se qu'il a dans le ficher et le met dans content
		printf("Pere : Je suis le pere, le pid de mon fils est %d.\n", pid);
	}
	return(0);
}


int	trans_heredoc(t_task **token)
{
	char	*temp;

	if ((*token)->content[1] != '>' && (*token)->content[1] != '<')
	{
		if ((*token)->content[0] == '>')
			(*token)->type = 1;
		else
			(*token)->type = 2;
		temp = ft_substr((*token)->content, 1, ft_strlen((*token)->content));
		free((*token)->content);
		(*token)->content = temp;
		return (0);
	}
	if ((*token)->content[0] != (*token)->content[1])
		return (1);
	// if ((*token)->content[1] == '<')
	// 	return (for_d_enter(token));
	(*token)->type = 3;
	temp = ft_substr((*token)->content, 2, ft_strlen((*token)->content));
	free((*token)->content);
	(*token)->content = temp;
	return (0);
}
