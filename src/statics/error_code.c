/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:29:06 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/13 13:33:25 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	*error_code(void)
{
	static int	err = 0;

	return (&err);
}

void	set_error(int code)
{
	int	*err;

	err = error_code();
	*err = code;
}

int	get_error(void)
{
	return (*error_code());
}
