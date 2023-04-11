/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:45:36 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/11 13:57:11 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exitin(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
		i++;
	if (i > 2)
	{
		ft_printf("too many arguments\n");
		mini_exit(0);
	}
	if (i == 2)
	{
		//verify if its number, convert to int and exit
	}
	mini_exit(0);
}
