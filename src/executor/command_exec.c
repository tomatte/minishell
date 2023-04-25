/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:48:30 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	normal_exec(t_command *command)
{
	int		err;
	char	first_char;

	first_char = command->args[0][0];
	if (first_char != '.' && first_char != '/')
		return ;
	err = execve(command->args[0], command->args, get_evars_arr());
	normal_exec_error(err, command);
}

static void	inpath_exec(t_command *command)
{
	char	**paths;
	char	first_char;
	int		i;
	int		err;

	first_char = command->args[0][0];
	if (first_char == '.' || first_char == '/')
		return ;
	paths = get_paths(command->args[0]);
	i = -1;
	while (paths[++i])
		err = execve(paths[i], command->args, get_evars_arr());
	inpath_exec_error(err, command->args[0]);
}

static void	try_execve(t_command *command)
{
	normal_exec(command);
	inpath_exec(command);
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
