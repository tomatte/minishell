/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_task.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:58:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/16 13:41:30 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	is_pipe_task(t_list *tokens)
{
	t_token	*token;

	token = (t_token *) tokens->content;
	return (token->id == PIPE);
}

void	pipe_task(t_task *task, t_list *tokens)
{
	if (!is_pipe_task(tokens))
		return ;
	tokens = tokens->next;
	free(task->args);
	command_task(task, tokens);
	task->type = PIPE;
}
