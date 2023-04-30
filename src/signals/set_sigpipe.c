/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sigpipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:30:58 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/29 21:31:39 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	sigpipe_handler(int sig)
{
	(void) sig;
	mini_exit(0);
}

void	set_sigpipe(void)
{
	signal(SIGPIPE, sigpipe_handler);
}
