/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:54:17 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/18 10:03:24 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*get_node(char *value, int type, int id)
{
	t_list	*node;
	t_token	*tkn;

	tkn = new_token(ft_strdup(value), type, id);
	node = lstnew_track(tkn);
	return (node);
}

t_list	*find_heredoc(t_list *tokens)
{
	while (tokens)
	{
		if (token(tokens)->id == HERE_DOC)
			return (tokens);
		tokens = tokens->next;
	}
	return (NULL);
}
