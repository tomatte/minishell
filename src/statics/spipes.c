/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spipes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:16:01 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/23 14:38:19 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	***spipes(void)
{
	static int	**pfds = NULL;

	return (&pfds);
}

void	start_pfds(int **pfds)
{
	int	***spfds;

	spfds = spipes();
	*spfds = pfds;
}

void	close_pfds(void)
{
	int	***pfds;

	pfds = spipes();
	if (*pfds == NULL)
		return ;
	close_pipes(*pfds);
	*pfds = NULL;
}
