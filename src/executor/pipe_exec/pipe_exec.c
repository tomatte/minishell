/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:00:02 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/29 09:59:08 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	pipe_exec(t_list *tokens)
{
	t_list	*commands;
	int		**pipedes;

	if (!is_operator(tokens, PIPE))
		return ;
	pipedes = get_pipedes(tokens);
	commands = get_commands(tokens, pipedes);
	exec_commands(commands, pipedes);
	close_pipes(pipedes);
}
