/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:27:35 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/19 10:27:25 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*next_pipe(t_list *tokens)
{
	while (1)
	{
		tokens = next_operator(tokens);
		while (is_redirect(tokens))
			tokens = next_operator(tokens);
		break ;
	}
	if (is_operator(tokens, PIPE))
		return (tokens);
	else
		return (NULL);
}

t_list	*next_pipe2(t_list *tokens)
{
	while (1)
	{
		tokens = next_operator(tokens);
		while (is_redirect(tokens))
			tokens = next_operator(tokens);
		break ;
	}
	if (is_operator(tokens, PIPE))
		return (tokens->next);
	else
		return (NULL);
}
