/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:45:36 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/14 12:23:05 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exitin(t_command *cmd)
{
	int	err;

	err = 0;
	if (cmd->args[1])
	{
		err = ft_atoi(cmd->args[1]);
		if (err == 0)
			err = 2;
	}
	mini_exit(err);
}
