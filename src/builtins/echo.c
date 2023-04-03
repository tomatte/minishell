/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:01:06 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/03 16:20:18 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	echo(t_command *cmd)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	if (ft_streq(cmd->args[1], "-n"))
	{
		n = 1;
		i = 1;
	}
	while (cmd->args[++i])
	{
		if (i > 1)
			ft_putstr_fd(" ", cmd->output_fd);
		ft_putstr_fd(cmd->args[i], cmd->output_fd);
	}
	if (n == 0)
		ft_putstr_fd("\n", cmd->output_fd);
}
