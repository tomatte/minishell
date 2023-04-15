/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:29:10 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/15 14:16:16 by dbrandao         ###   ########.fr       */
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

static void	remove_heredoc(t_list *tokens)
{
	t_list	*before;
	t_list	*after;

	before = tokens;
	while (token(before->next)->id != HERE_DOC)
		before = before->next;
	after = before->next->next->next;
	before->next = after;
}

void	heredoc_convert(t_list **tokens)
{
	t_list	*doc;
	t_list	*args;

	set_sdoc(0);
	while (1)
	{
		doc = find_heredoc(*tokens);
		if (doc == NULL)
			return ;
		set_sdoc(1);
		args = read_doc((t_token *) doc->next->content);
		if (in_error())
			return ;
		convert_to_tokens(tokens, args);
		remove_heredoc(*tokens);
	}
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