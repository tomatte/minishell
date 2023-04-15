/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:37:33 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/15 14:53:29 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	sig_handler(int sig)
{
	(void) sig;
	set_state(-1);
	set_error(130);
	ft_printf("\n%s", get_prompt_msg());
}

void	set_signals(void)
{
	signal(SIGINT, sig_handler);
}
