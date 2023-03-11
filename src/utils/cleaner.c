/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:13:04 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/11 10:29:19 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	clear_tokens(t_list *tokens)
{
	t_token	*token;
	t_list	*next;

	while (tokens)
	{
		next = tokens->next;
		token = (t_token *) tokens->content;
		free(token->value);
		free(token);
		free(tokens);
		tokens = next;
	}
}

void	cleaner(char *str, t_list *tokens)
{
	clear_tokens(tokens);
	free(str);
}
