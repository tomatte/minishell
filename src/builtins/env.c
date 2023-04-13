/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:58:26 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/13 18:33:46 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	many_args_err(t_command *cmd)
{
	int		i;

	i = 0;
	while (cmd->args[i])
		i++;
	if (i >= 2)
	{
		ft_putstr_fd("env: Too many arguments\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}

void	env(t_command *cmd)
{
	t_list	*vars;

	if (many_args_err(cmd))
		return (set_error(1));
	vars = get_evars2();
	while (vars)
	{
		ft_printf("%s\n", (char *) vars->content);
		vars = vars->next;
	}
	set_error(0);
}
