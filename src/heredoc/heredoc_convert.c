/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:29:10 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/05 17:37:41 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_list	*find_heredoc(t_list *tokens)
{
	while (tokens)
	{
		if (token(tokens)->id == HERE_DOC)
			return (tokens);
		tokens = tokens->next;
	}
	return (NULL);
}

void	heredoc_convert(t_list **tokens)
{
	t_list	*doc;

	doc = find_heredoc(*tokens);
	print_tokens(doc);
}

//encontrar here_doc
//ler input
//adicionar echo antes do commando anterior ao here_doc
//adicionar args após echo
//adicionar pipe após args
//fim
/* 
	[cat] [<<] [END]

	args = get_next_line until "END"

	[echo] [args] | [cat]


 lst_add_front
 */