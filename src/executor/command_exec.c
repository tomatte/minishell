/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:48:30 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/11 12:03:00 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	try_execve(t_command *command)
{
	char	**paths;
	char	*cmd;
	int		i;

	cmd = command->args[0];
	execve(cmd, command->args, get_evars());
	paths = get_paths(cmd);
	i = -1;
	while (paths[++i])
	{
		command->args[0] = paths[i];
		execve(command->args[0], command->args, get_evars());
	}
	command->args[0] = cmd;
}

static int	try_builtin(t_command *command)
{
	if (ft_streq(command->args[0], "echo"))
		echo(command);
	else if (ft_streq(command->args[0], "heredoc") && get_sdoc())
		heredoc(command);
	else if (ft_streq(command->args[0], "cd"))
		cd(command);
	else
		return (0);
	return (1);
}

static void	exit_error(int code)
{
	close(R);
	close(W);
	destroy_memories();
	destroy_evars();
	clear_history();
	exit(code);
}

void	command_exec(t_command *command)
{
	if (try_builtin(command))
		exit_error(0);
	else
	{
		try_execve(command);
		cmd_not_found(command->args[0]);
		exit_error(127);
	}
}
