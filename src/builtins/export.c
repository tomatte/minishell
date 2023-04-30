/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:07:40 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/29 21:33:51 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	print_export_env(char *env)
{
	ft_putstr("declare -x ");
	while (*env && *env != '=')
		ft_putchar(*env++);
	ft_putstr("=\"");
	ft_putstr(env + 1);
	ft_putstr("\"\n");
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
	if (ft_strchr(INVALIDS2, *str))
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

	set_sigpipe();
	set_error(0);
	i = 0;
	while (cmd->args[i])
		i++;
	if (i == 1)
		export_print();
	else
		export_var(cmd);
}
