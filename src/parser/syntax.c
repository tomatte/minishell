/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:26:17 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	is_redirec(int r)
{
	if (r >= 15 && r <= 18)
		return (1);
	return (0);
}

static void	near_unexpected_token(t_token *token, t_list *next)
{
	if (token->id == PIPE && get_state() == START)
		return (nut_error(token->value));
	if (is_redirec(get_state()) && is_redirec(token->id))
		return (nut_error(token->value));
	if (is_redirec(get_state()) && token->id == PIPE)
		return (nut_error(token->value));
	if (get_state() == PIPE && token->id == PIPE)
		return (nut_error(token->value));
	if (token->type == OPERATOR && next == NULL)
		return (nut_error("newline"));
}

void	syntax(t_list *tokens)
{
	near_unexpected_token(tokens->content, tokens->next);
}
