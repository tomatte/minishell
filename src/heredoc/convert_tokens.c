/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:00:22 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/18 15:42:32 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_list	*get_right_token(t_list *tokens)
{
	t_list	*right;
	t_list	*here;

	here = find_heredoc(tokens);
	right = here->next->next;
	if (right == NULL)
		return (NULL);
	if (token(right)->id == PIPE)
		right = right->next;
	return (right);
}

static void	remove_heredoc(t_list **tokens)
{
	t_list	*here;
	t_list	*left;
	t_list	*right;

	here = find_heredoc(*tokens);
	left = get_left_token(*tokens);
	if (left == NULL)
	{
		*tokens = here->next->next;
		return ;
	}
	right = get_right_token(*tokens);
	left->next = right;
}

static void	add_new_heredoc(t_list **tokens, t_list *cmd, t_list *new_nodes)
{
	t_list	*aux;

	if (cmd == NULL)
		return ;
	ft_lstadd_back(&new_nodes, get_node("|", OPERATOR, PIPE));
	if (*tokens == cmd)
	{
		ft_lstlast(new_nodes)->next = cmd;
		*tokens = new_nodes;
		return ;
	}
	aux = *tokens;
	while (aux)
	{
		if (aux->next == cmd)
			break ;
		aux = aux->next;
	}
	aux->next = new_nodes;
	ft_lstlast(new_nodes)->next = cmd;
}

static void	ptvalues(t_list *tokens)
{
	while (tokens)
	{
		ft_printf("%s ", token(tokens)->value);
		tokens = tokens->next;
	}
	ft_printf("\n");
}

static void	pipe_last_case(t_list *tokens)
{
	t_list	*last;
	t_list	*aux;

	last = ft_lstlast(tokens);
	if (last == NULL || token(last)->id != PIPE)
		return ;
	aux = tokens;
	while (aux)
	{
		if (aux->next == last)
			break ;
		aux = aux->next;
	}
	aux->next = NULL;
}

void	convert_tokens(t_list **tokens, t_list *heredoc_list)
{
	t_list	*cmd;

	while (find_heredoc(*tokens))
	{
		cmd = get_heredoc_cmd(*tokens);
		remove_heredoc(tokens);
		add_new_heredoc(tokens, cmd, heredoc_list->content);
	}
	pipe_last_case(*tokens);
}
