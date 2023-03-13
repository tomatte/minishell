/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:26:17 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/13 15:19:00 by dbrandao         ###   ########.fr       */
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
	int		s;

	s = get_state();
	if (token->id == PIPE && s == START)
		return (nut_error(token->value));
	if (is_operator_state() && token->type == OPERATOR)
		return (nut_error(token->value));
	if (token->type == OPERATOR && next == NULL)
		return (nut_error("newline"));
}

void	syntax(t_list *tokens)
{
	near_unexpected_token(tokens->content, tokens->next);
}
