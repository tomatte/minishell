/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:58:26 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/14 11:00:52 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* static int	no_such_file(void)
{

} */

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
		i++;
	}
	return (0);
}

void	env(t_command *cmd)
{
	t_list	*vars;

	if (verify_args(cmd))
		return ;
	vars = get_evars2();
	while (vars)
	{
		ft_printf("%s\n", (char *) vars->content);
		vars = vars->next;
	}
	set_error(0);
}
