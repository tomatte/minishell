/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:08:04 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/14 22:03:25 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	*state(void)
{
	static int	s = 0;

	return (&s);
}

void	set_state(int id)
{
	int	*s;

	s = state();
	*s = id;
}

int	get_state(void)
{
	return (*state());
}
