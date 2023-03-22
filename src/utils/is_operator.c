/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:06:00 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/22 11:28:04 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_operator(t_list *tokens, int operator_id)
{
	while (tokens && token(tokens)->type != OPERATOR)
		tokens = tokens->next;
	if (tokens == NULL)
		return (0);
	return (token(tokens)->id == operator_id);
}
