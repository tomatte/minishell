/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:14:56 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/22 15:08:12 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_directory(t_command *cmd)
{
	struct stat	path_stat;
	int			aux;

	aux = stat(cmd->args[0], &path_stat);
	if (aux == -1)
		return (0);
	if (S_ISDIR(path_stat.st_mode))
		return (1);
	return (0);
}

void	normal_exec_error(int err, t_command *cmd)
{
	if (err == 0)
		return ;
	ft_putstr_fd(cmd->args[0], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (is_directory(cmd))
		ft_putstr_fd("Is a directory", STDERR_FILENO);
	else
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (errno == ENOENT)
		mini_exit(127);
	else
		mini_exit(126);
}

void	inpath_exec_error(int err, char *cmd)
{
	if (err == 0)
		return ;
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	mini_exit(127);
}
