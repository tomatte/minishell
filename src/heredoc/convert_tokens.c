/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:00:22 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/18 14:50:40 by dbrandao         ###   ########.fr       */
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

void	convert_tokens(t_list **tokens, t_list *heredoc_list)
{
	t_list	*cmd;

	print_tokens(*tokens);
	cmd = get_heredoc_cmd(*tokens);
	remove_heredoc(tokens);
	print_tokens(*tokens);
}
