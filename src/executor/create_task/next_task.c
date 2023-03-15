/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_task.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:40:05 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/15 20:48:00 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	next_operator(t_list **tokens)
{
	t_token	*token;

	while (1)
	{
		*tokens = (*tokens)->next;
		token = (t_token *)(*tokens)->content;
		if (token->type == OPERATOR)
			break;
	}
}

void	next_task(t_list **tokens, t_task *task)
{
	command_task(task, *tokens);
	next_operator(tokens);
}
