/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:54:39 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	unset(t_command *cmd)
{
	int	i;

	if (is_option(cmd->args[1]))
	{
		invalid_option(cmd->args[0], cmd->args[1]);
		return ;
	}
	i = 0;
	while (cmd->args[++i])
		remove_evar(cmd->args[i]);
	set_error(0);
}
