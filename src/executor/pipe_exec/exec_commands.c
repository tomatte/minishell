/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:49:23 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/03 14:54:53 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	create_fork(t_list *commands)
{
	t_command	*command;

	command = commands->content;
	command->pid = fork();
}

static void	exit_error(t_command *command)
{
	ft_printf("error executing command %s\n", command->args[0]);
	close(R);
	close(W);
	destroy_memories();
	destroy_evars();
	clear_history();
	exit(1);
}

static void	exec_command(t_list *commands, int **pipedes)
{
	t_command	*command;

	command = (t_command *) commands->content;
	if (command->pid == 0)
	{
		dup2(command->input_fd, STDIN_FILENO);
		dup2(command->output_fd, STDOUT_FILENO);
		close_pipes(pipedes);
		command_exec(command);
		exit_error(command);
	}
}

void	exec_commands(t_list *commands, int **pipedes)
{
	while (commands)
	{
		create_fork(commands);
		exec_command(commands, pipedes);
		commands = commands->next;
	}
}
