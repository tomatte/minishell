/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:01:06 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/23 21:09:20 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_valid_option(char *str)
{
	if (!is_option(str))
		return (0);
	str++;
	while (*str)
	{
		if (*str != 'n')
			return (0);
		str++;
	}
	return (1);
}

void	echo(t_command *cmd)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	if (is_valid_option(cmd->args[1]))
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
