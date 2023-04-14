/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:01:06 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/13 23:56:31 by dbrandao         ###   ########.fr       */
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
		ft_putstr(cmd->args[i]);
		if (cmd->args[i + 1] != NULL)
			ft_putstr(" ");
	}
	if (n == 0)
		ft_putstr("\n");
	set_error(0);
}
