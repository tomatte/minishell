/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:07:40 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/12 14:49:29 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	export_print(void)
{
	char	**envs;

	envs = get_evars_arr();
	if (envs == NULL)
		return ;
	while (*envs)
		ft_printf("declare -x %s\n", *envs++);
}

static int	is_valid(char *str)
{
	if (ft_strchr(INVALIDS1, str[0]))
	{
		ft_printf("invalid char\n");
		return (0);
	}
	if (ft_strchr(INVALIDS2, str[0]))
	{
		ft_printf("invalid char\n");
		return (0);
	}
	return (1);
}

static void	export_var(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[++i])
	{
		if (!is_valid(cmd->args[i]))
			continue ;
		add_evar2(cmd->args[i]);
	}
}

void	export(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
		i++;
	if (i == 1)
		export_print();
	else
		export_var(cmd);
}
