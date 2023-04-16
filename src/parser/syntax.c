/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:26:17 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/16 15:55:24 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_operator_state(void)
{
	int	s;

	s = get_state();
	if (s >= HERE_DOC && s <= PIPE)
		return (1);
	return (0);
}

static void	near_unexpected_token(t_token *token, t_list *next)
{
	if (token->id == PIPE && get_state() == START)
		return (nut_error(token->value));
	if (is_operator_state() && token->type == OPERATOR
		&& token->id != HERE_DOC)
		return (nut_error(token->value));
	if (token->type == OPERATOR && next == NULL)
		return (nut_error("newline"));
}

void	syntax(t_list *tokens)
{
	near_unexpected_token(tokens->content, tokens->next);
}
