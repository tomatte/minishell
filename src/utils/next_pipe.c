/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:27:35 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*next_pipe(t_list *tokens)
{
	tokens = next_operator(tokens);
	while (is_redirect(tokens))
		tokens = next_operator(tokens);
	if (is_operator(tokens, PIPE))
		return (tokens);
	else
		return (NULL);
}

t_list	*next_pipe2(t_list *tokens)
{
	tokens = next_pipe(tokens);
	if (tokens)
		return (tokens->next);
	return (tokens);
}

t_list	*next_pipe3(t_list *tokens)
{
	while (tokens && token(tokens)->id != PIPE)
		tokens = tokens->next;
	if (tokens && token(tokens)->id == PIPE)
		tokens = tokens->next;
	return (tokens);
}
