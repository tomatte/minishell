/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:16:40 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/19 10:17:10 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	no_command(t_list *tokens)
{
	int		redir;

	redir = 0;
	if (tokens && token(tokens)->id == ARG)
	{
		token(tokens)->id = EXEC;
		return (0);
	}
	while (tokens)
	{
		if (token(tokens)->id == EXEC)
			return (0);
		if (is_redirect(tokens))
			redir = 1;
		if (redir && token(tokens)->id == ARG)
		{
			token(tokens)->id = EXEC;
			return (0);
		}
		if (token(tokens)->id == PIPE)
			return (1);
		tokens = tokens->next;
	}
	return (1);
}
