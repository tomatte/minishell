/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:41:30 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/06 14:26:06 by dbrandao         ###   ########.fr       */
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

	echo_node = get_node("echo", WORD, EXEC);
	echo_node->next = args;
	pipe_node = get_node("|", OPERATOR, PIPE);
	ft_lstlast(args)->next = pipe_node;
	ft_lstadd_front(tokens, pipe_node);
	*tokens = echo_node;
}

static void	add_to_middle(t_list **tokens, t_list *args)
{
	t_list	*mid;
	t_list	*aux;

	mid = *tokens;
	while (token(mid->next->next)->id != HERE_DOC)
		mid = mid->next;
	aux = mid->next;
	add_to_begin(&aux, args);
	mid->next = aux;
}

void	convert_to_tokens(t_list **tokens, t_list *args)
{
	if (is_operator(next_operator((*tokens)), HERE_DOC))
		add_to_begin(tokens, args);
	else
		add_to_middle(tokens, args);
}

/* 
	1 - [ls] [arg] [|] [cat] [<<] [end] -> [ls] [|] [echo]
	2 - [cat] [<<] [end] -> [echo] [args] [|] [cat] [...]
 */