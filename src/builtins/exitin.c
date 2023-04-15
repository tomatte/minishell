/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:45:36 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/15 16:52:09 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exitin(t_command *cmd)
{
	int	err;

	err = 0;
	if (cmd->args[1])
	{
		//TODO
		//give back error if it's not number
		//give back error if it's more than one argument
		err = ft_atoi(cmd->args[1]);
	}
	else
		err = get_error();
	mini_exit(err);
}
