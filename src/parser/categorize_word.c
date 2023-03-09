/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   categorize_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:53:14 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/09 17:54:34 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	decider(t_list *tokens)
{
	t_token	*token;

	token = tokens->content;
	if (token->type == WORD && get_state() == START)
	{
		set_state(WORD);
		token->id = EXEC;
	}
	else if (token->type == WORD && get_state() == WORD)
	{
		token->id = ARG;
	}
}

void	categorize_word(t_list *tokens)
{
	t_token	*token;

	while (tokens)
	{
		decider(tokens);
		tokens = tokens->next;
	}
}
