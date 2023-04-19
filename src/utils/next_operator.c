/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:58:56 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/19 10:08:03 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*next_operator(t_list *tokens)
{
	if (tokens && token(tokens)->type == OPERATOR)
		tokens = tokens->next;
	while (tokens && token(tokens)->type != OPERATOR)
		tokens = tokens->next;
	return (tokens);
}

t_list	*next_operator2(t_list *tokens)
{
	while (tokens && token(tokens)->type != OPERATOR)
		tokens = tokens->next;
	return (tokens);
}
