/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:38:01 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/14 12:12:31 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	cd_home(void)
{
	char	*path;
	int		err;

	path = ft_strjoin("/home/", getenv("USER"));
	err = chdir(path);
	if (err != 0)
		no_such_file("cd", path);
	free(path);
	return (err != 0);
}

static int	cd_many_args(void)
{
	ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
	return (1);
}

static int	cd_path(t_command *cmd)
{
	int	err;

	err = chdir(cmd->args[1]);
	if (err != 0)
		no_such_file(cmd->args[0], cmd->args[1]);
	return (err != 0);
}

void	cd(t_command *cmd)
{
	int	i;
	int	err;

	if (is_option(cmd->args[1]))
		return (invalid_option(cmd->args[0], cmd->args[1]));
	i = 0;
	while (cmd->args[i])
		i++;
	if (i > 2)
		err = cd_many_args();
	else if (i == 1)
		err = cd_home();
	else
		err = cd_path(cmd);
	set_error(err);
}
