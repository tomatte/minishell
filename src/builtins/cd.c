/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:38:01 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/13 15:35:54 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	cd_not_found(char *path)
{
	ft_putstr_fd("cd: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(" No such file or directory\n", STDERR_FILENO);
	set_error(1);
}

static int	cd_home(void)
{
	char	*path;
	int		err;

	path = ft_strjoin("/home/", getenv("USER"));
	err = chdir(path);
	if (err != 0)
		cd_not_found(path);
	free(path);
	return (err);
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
		cd_not_found(cmd->args[1]);
	return (err);
}

void	cd(t_command *cmd)
{
	int	i;
	int	err;

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
