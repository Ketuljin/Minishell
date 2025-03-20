/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdunatte <vdunatte@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:56:47 by rvandepu          #+#    #+#             */
/*   Updated: 2025/03/19 21:34:57 by vdunatte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_last_sig = 0;

static void	int_handler(int sig)
{
	(void)sig;
	write(2, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_last_sig = 130;
}

static void	save_sig(int sig)
{
	(void)sig;
	close(g_last_sig);
	g_last_sig = 130;
	exit(130);
}

void	set_signals(t_setsig set)
{
	if (set == S_INTERACTIVE)
	{
		sigaction(SIGINT, &(struct sigaction){.sa_handler = int_handler}, NULL);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGPIPE, SIG_IGN);
	}
	else if (set == S_HEREDOC)
	{
		sigaction(SIGINT, &(struct sigaction){.sa_handler = save_sig}, NULL);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGPIPE, SIG_IGN);
	}
	else if (set == S_IGNORE)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGPIPE, SIG_IGN);
	}
	else if (set == S_DEFAULT)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		signal(SIGPIPE, SIG_DFL);
	}
}
