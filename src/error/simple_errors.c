/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:40:09 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/14 11:06:12 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cmd_not_found(char *cmd)
{
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd("command not found\n", STDERR_FILENO);
}

void	invalid_option(char *cmd, char *opt)
{
	if (opt == NULL)
		return ;
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": invalid option ", STDERR_FILENO);
	if (ft_strlen(opt) == 2)
	{
		ft_putstr_fd("-- '", STDERR_FILENO);
		ft_putstr_fd(opt + 1, STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd("'", STDERR_FILENO);
		ft_putstr_fd(opt, STDERR_FILENO);
	}
	ft_putstr_fd("'\n", STDERR_FILENO);
	set_error(2);
	return ;
}

void	no_such_file(char *cmd, char *file)
{
	if (file == NULL || cmd == NULL)
		return ;
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": '", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd("': No such file or directory\n", STDERR_FILENO);
	set_error(3);
}
