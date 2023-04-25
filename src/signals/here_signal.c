/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:59:59 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/25 20:19:04 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	here_handler(int sig)
{
	(void) sig;
	ft_putstr("\n");
	mini_exit(130);
}

void	set_sig_here(void)
{
	signal(SIGINT, here_handler);
}

static void	none(int sig)
{
	(void) sig;
}

void	disable_signals(void)
{
	signal(SIGINT, none);
}
