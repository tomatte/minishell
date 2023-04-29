/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:37:33 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/29 18:31:07 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	sig_handler(int sig)
{
	(void) sig;
	set_state(-1);
	set_error(130);
	rl_replace_line("", 0);
	rl_on_new_line();
	ft_putstr("\n");
	rl_redisplay();
}

static void	sigpipe_handler(int sig)
{
	(void) sig;
	mini_exit(0);
}

void	set_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_handler);
	signal(SIGPIPE, sigpipe_handler);
}
