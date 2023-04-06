/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:29:10 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/06 12:59:11 by dbrandao         ###   ########.fr       */
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
	t_list	*args;

	doc = find_heredoc(*tokens);
	if (doc == NULL)
		return ;
	args = read_doc((t_token *) doc->next->content);
	//print_tokens(*tokens);
	convert_to_tokens(tokens, args);
	//print_tokens(*tokens);
	//print_tokens(args);
}

//encontrar here_doc x
//ler input x
//convert to word tokens x
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