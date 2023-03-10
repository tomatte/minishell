/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:37:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/10 15:02:15 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	keep_state(t_token *token)
{
	if (token->type == OPERATOR)
		set_state(token->id);
}

void	parser(t_list *tokens)
{
	t_token	*token;

	if (tokens == NULL)
		return ;
	ft_printf("Parser started.\n");
	while (tokens)
	{
		token = (t_token *) tokens->content;
		categorize_word(token);
		keep_state(token);
		tokens = tokens->next;
	}
}
