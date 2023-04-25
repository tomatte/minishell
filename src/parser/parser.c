/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:37:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 23:30:58 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	int		has_exec;

	if (tokens == NULL)
		return ;
	has_exec = -1;
	while (tokens && !in_error())
	{
		token = (t_token *) tokens->content;
		categorize_word(token, &has_exec);
		syntax(tokens);
		keep_state(token);
		tokens = tokens->next;
	}
}
