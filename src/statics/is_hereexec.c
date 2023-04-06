/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hereexec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:47:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/06 14:49:19 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	*sdoc(void)
{
	static int	d = 0;

	return (&d);
}

void	set_sdoc(int id)
{
	int	*d;

	d = sdoc();
	*d = id;
}

int	get_sdoc(void)
{
	return (*sdoc());
}
