/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:00:02 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/05 11:25:47 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	is_pipe_exec(t_list *tokens)
{
	if (tokens == NULL)
		return (0);
	if (next_operator(tokens) == NULL)
		return (0);
	while (is_redirect(next_operator(tokens)))
		tokens = next_operator(tokens);
	if (is_operator(next_operator(tokens), PIPE))
		return (1);
	return (0);
}

void	pipe_exec(t_list *tokens)
{
	t_list	*commands;
	int		**pipedes;

	if (!is_pipe_exec(tokens))
		return ;
	pipedes = get_pipedes(tokens);
	commands = get_commands(tokens, pipedes);
	exec_commands(tokens, commands, pipedes);
	close_pipes(pipedes);
}
