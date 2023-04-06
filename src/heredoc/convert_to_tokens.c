/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:41:30 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/06 12:52:35 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_list	*get_node(char *value, int type, int id)
{
	t_list	*node;
	t_token	*tkn;

	tkn = new_token(ft_strdup(value), type, id);
	node = lstnew_track(tkn);
	return (node);
}

static void	add_to_begin(t_list **tokens, t_list *args)
{
	t_list	*echo_node;
	t_list	*pipe_node;

	if (!is_operator((*tokens)->next, HERE_DOC))
		return ;
	echo_node = get_node("echo", WORD, EXEC);
	echo_node->next = args;
	pipe_node = get_node("|", OPERATOR, PIPE);
	ft_lstlast(args)->next = pipe_node;
	ft_lstadd_front(tokens, pipe_node);
	*tokens = echo_node;
}

void	convert_to_tokens(t_list **tokens, t_list *args)
{
	add_to_begin(tokens, args);
}

/* 
	1 - [ls] [arg] [|] [cat] [<<] [end] -> [ls] [|] [echo]
	2 - [cat] [<<] [end] -> [echo] [args] [|] [cat] [...]
 */