/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:24:26 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/18 19:37:13 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_redirect(t_list *tokens)
{
	if (tokens == NULL)
		return (0);
	if (token(tokens)->id == R_APPEND_OUT)
		return (1);
	else if (token(tokens)->id == R_OUTPUT)
		return (1);
	else if (token(tokens)->id == R_INPUT)
		return (1);
	else if (token(tokens)->id == HERE_DOC)
		return (1);
	return (0);
}
