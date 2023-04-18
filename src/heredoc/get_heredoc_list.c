/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:30:24 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/18 10:57:54 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_list	*new_heredoc(t_list *args)
{
	t_list	*node;

	node = get_node("heredoc", WORD, EXEC);
	node->next = args;
	return (node);
}

//to test
void	print_heredoc_list(t_list *heredoc_list)
{
	while (heredoc_list)
	{
		print_tokens((t_list *) (heredoc_list->content));
		heredoc_list = heredoc_list->next;
	}
}

t_list	*get_heredoc_list(t_list *tokens)
{
	t_list	*heredoc_list;
	t_list	*heredoc_nodes;
	t_list	*args;

	heredoc_list = NULL;
	while (find_heredoc(tokens))
	{
		args = read_doc(tokens);
		heredoc_nodes = new_heredoc(args);
		ft_lstadd_back(&heredoc_list, lstnew_track(heredoc_nodes));
		tokens = find_heredoc(tokens)->next;
	}
	return (heredoc_list);
}
