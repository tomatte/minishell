/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:49:23 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/24 12:23:52 by dbrandao         ###   ########.fr       */
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

static void	exec_command(t_pipe *data)
{
	t_command	*command;

	command = (t_command *) data->commands->content;
	if (command->pid == 0)
	{
		redirect_fds(command);
		close_pipes(data->pipedes);
		execv(command->args[0], command->args);
		ft_printf("Error executing command %s\n", command->args[0]);
		exit(0);
	}
}

void	exec_commands(t_pipe *data)
{
	while (data->commands)
	{
		create_fork(data->commands);
		exec_command(data);
		data->commands = data->commands->next;
	}
	while (wait(NULL) != -1);
}
