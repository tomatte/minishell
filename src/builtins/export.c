/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:07:40 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/14 12:32:39 by dbrandao         ###   ########.fr       */
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
		invalid_identifier("export", str);
	else if (ft_strchr(INVALIDS2, str[0]))
		invalid_identifier("export", str);
	else
		return (1);
	return (0);
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

	set_error(0);
	i = 0;
	while (cmd->args[i])
		i++;
	if (i == 1)
		export_print();
	else
		export_var(cmd);
}
