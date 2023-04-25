/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:00:02 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:59 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	is_simple_exec(t_list *tokens)
{
	if (tokens == NULL)
		return (0);
	while (tokens)
	{
		if (token(tokens)->id == PIPE)
			return (0);
		tokens = tokens->next;
	}
	return (1);
}

static void	wait_childs_ordered(t_list *commands)
{
	t_command	*cmd;
	int			status;

	status = 0;
	while (commands)
	{
		cmd = (t_command *) commands->content;
		waitpid(cmd->pid, &status, WUNTRACED);
		set_error(WEXITSTATUS(status));
		commands = commands->next;
	}
}

void	pipe_exec(t_list *tokens)
{
	t_list	*commands;
	int		**pipedes;

	if (is_simple_exec(tokens))
		return ;
	pipedes = get_pipedes(tokens);
	commands = get_commands(tokens, pipedes);
	exec_commands(tokens, commands, pipedes);
	close_pipes(pipedes);
	wait_childs_ordered(commands);
}
