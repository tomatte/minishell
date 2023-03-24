/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:49:23 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/24 12:42:24 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	create_fork(t_list *commands)
{
	t_command	*command;

	command = commands->content;
	command->pid = fork();
}

static void	redirect_fds(t_command *command)
{
	dup2(command->input_fd, STDIN_FILENO);
	dup2(command->output_fd, STDOUT_FILENO);
}

static void	exec_command(t_list *commands, int **pipedes)
{
	t_command	*command;

	command = (t_command *) commands->content;
	if (command->pid == 0)
	{
		redirect_fds(command);
		close_pipes(pipedes);
		execv(command->args[0], command->args);
		ft_printf("Error executing command %s\n", command->args[0]);
		exit(0);
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
	while (wait(NULL) != -1);
}
