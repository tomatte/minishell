/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:58:26 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/29 21:33:38 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	verify_args(t_command *cmd)
{
	int	i;

	i = 1;
	while (cmd->args[i])
	{
		if (is_option(cmd->args[i]))
		{
			invalid_option(cmd->args[0], cmd->args[i]);
			return (1);
		}
		else
		{
			no_such_file(cmd->args[0], cmd->args[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	env(t_command *cmd)
{
	t_list	*vars;

	set_sigpipe();
	if (verify_args(cmd))
		return ;
	vars = get_evars2();
	while (vars)
	{
		ft_putstr((char *) vars->content);
		ft_putchar('\n');
		vars = vars->next;
	}
	set_error(0);
}
