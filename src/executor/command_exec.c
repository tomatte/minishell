/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:48:30 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/18 22:06:39 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	try_execve(t_command *command)
{
	char	**paths;
	int		i;

	execve(command->args[0], command->args, get_evars_arr());
	paths = get_paths(command->args[0]);
	i = -1;
	while (paths[++i])
		execve(paths[i], command->args, get_evars_arr());
}

static int	try_builtin(t_command *command)
{
	if (ft_streq(command->args[0], "echo"))
		echo(command);
	else if (ft_streq(command->args[0], "cd"))
		cd(command);
	else if (ft_streq(command->args[0], "exit"))
		exitin(command);
	else if (ft_streq(command->args[0], "pwd"))
		pwd(command);
	else if (ft_streq(command->args[0], "env"))
		env(command);
	else if (ft_streq(command->args[0], "export"))
		export(command);
	else if (ft_streq(command->args[0], "unset"))
		unset(command);
	else
		return (0);
	return (1);
}

void	command_exec(t_command *command)
{
	if (try_builtin(command))
		mini_exit(get_error());
	else
	{
		try_execve(command);
		cmd_not_found(command->args[0]);
		mini_exit(127);
	}
}
