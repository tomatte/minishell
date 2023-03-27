/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:49:23 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/26 23:28:25 by dbrandao         ###   ########.fr       */
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

//create a memory tracker
//so instead of use a malloc function I will use an alloc_track function
//then the memory will be tracked from allocation
static void	try_execve(t_command *command, char **envp)
{
	char	**paths;
	char	*cmd;
	int		i;

	cmd = command->args[0];
	execve(cmd, command->args, envp);
	paths = get_paths(envp, cmd);
	i = -1;
	while (paths[++i])
	{
		command->args[0] = paths[i];
		execve(command->args[0], command->args, envp);
	}
	command->args[0] = cmd;
}

static void	exec_command(t_list *commands, int **pipedes, char **envp)
{
	t_command	*command;

	command = (t_command *) commands->content;
	if (command->pid == 0)
	{
		redirect_fds(command);
		close_pipes(pipedes);
		try_execve(command, envp);
		ft_printf("Error executing command %s\n", command->args[0]);
		exit(0);
	}
}

void	exec_commands(t_list *commands, int **pipedes, char **envp)
{
	while (commands)
	{
		create_fork(commands);
		exec_command(commands, pipedes, envp);
		commands = commands->next;
	}
}