/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:07:40 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/25 17:24:04 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_export_env(char *env)
{
	ft_printf("declare -x ");
	while (*env && *env != '=')
		ft_putchar(*env++);
	ft_printf("=\"%s\"\n", (env + 1));
}

static void	export_print(void)
{
	char	**envs;

	envs = get_evars_arr();
	if (envs == NULL)
		return ;
	while (*envs)
		print_export_env(*envs++);
}

static int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		invalid_identifier("export", str);
		return (0);
	}
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			invalid_identifier("export", str);
			return (0);
		}
		i++;
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
		add_var_to_evars(cmd->args[i]);
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
