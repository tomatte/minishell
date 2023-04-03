/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:48:30 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/03 14:53:05 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* static void	builtin_exec(t_command *cmd)
{
	echo(cmd);
	tokens = next_operator(tokens);
} */

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

void	command_exec(t_command *command)
{
	try_execve(command);
}
