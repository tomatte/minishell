/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:08:04 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/08 13:29:32 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	state(int id)
{
	static int	s = 0;

	if (id != 0)
		s = id;
	return (s);
}

void	set_state(int id)
{
	state(id);
}

int		get_state(void)
{
	return (state(0));
}
