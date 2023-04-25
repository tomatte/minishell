/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:37:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	keep_state(t_token *token)
{
	if (get_state() < 0)
		return ;
	if (token->type == OPERATOR)
		set_state(token->id);
}

void	parser(t_list *tokens)
{
	t_token	*token;

	if (tokens == NULL)
		return ;
	while (tokens && !in_error())
	{
		token = (t_token *) tokens->content;
		categorize_word(token);
		syntax(tokens);
		keep_state(token);
		tokens = tokens->next;
	}
}
