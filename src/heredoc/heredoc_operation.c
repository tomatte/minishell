/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:29:10 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/18 10:16:14 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	heredoc_convert(t_list **tokens)
{
	t_list	*doc;
	t_list	*args;

/* 	if (in_error())
		return ; */
	while (1)
	{
		if (!find_heredoc(*tokens))
			return ;
		args = read_doc(*tokens);
		print_tokens(args);
		set_error(1); set_state(-1);
		if (in_error())
			return ;
	}
}


/* 
static t_list	*get_heredoc_list(tokens)
{
	t_list	*heredoc_list;
	t_list	*heredoc_node;
	t_list	*args;

	heredoc_list = NULL;
	while (find_heredoc(tokens))
	{
		args = read_doc(tokens);
		heredoc_node = new_heredoc(args);
		ft_lstadd_back(&heredocs, heredoc_node);
	}
}

static void	convert_tokens(tokens, heredoc_list)
{
	while (find_heredoc(tokens))
	{
		cmd = get_heredoc_cmd(tokens)
		remove_heredoc(tokens);
		add_new_heredoc(tokens, heredoc_list)
	}
}

 << eof cat
heredoc args | cat


 cat << eof
 heredoc args | cat

 << eof
 cat arg << eof
 cat arg << eof arg
 cat << eof arg << eof

 */