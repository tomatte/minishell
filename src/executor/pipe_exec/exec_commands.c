/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:49:23 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/15 16:28:39 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	create_fork(t_list *commands)
{
	t_command	*command;

	command = commands->content;
	command->pid = fork();
}

static void	add_redirects(t_list *tokens, t_list *commands)
{
	t_command	*command;
	int			redirects[2];

	command = (t_command *) commands->content;
	get_redirects(tokens, redirects);
	if (redirects[R] != STDIN_FILENO)
	{
		if (command->input_fd != STDIN_FILENO)
			close(command->input_fd);
		command->input_fd = redirects[R];
	}
	if (redirects[W] != STDOUT_FILENO)
	{
		if (command->output_fd != STDOUT_FILENO)
			close(command->output_fd);
		command->output_fd = redirects[W];
	}
}

static void	exec_command(t_list *commands, int **pipedes)
{
	t_command	*command;

	command = (t_command *) commands->content;
	if (command->pid == 0)
	{
		set_signals();
		dup2(command->input_fd, STDIN_FILENO);
		dup2(command->output_fd, STDOUT_FILENO);
		close_pipes(pipedes);
		command_exec(command);
	}
}

void	exec_commands(t_list *tokens, t_list *commands, int **pipedes)
{
	t_list	*aux;

	aux = tokens;
	while (commands)
	{
		add_redirects(aux, commands);
		signal(SIGINT, SIG_IGN);
		create_fork(commands);
		exec_command(commands, pipedes);
		commands = commands->next;
		aux = next_pipe(aux);
	}
}
