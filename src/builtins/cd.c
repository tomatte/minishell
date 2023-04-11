/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:38:01 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/11 11:57:54 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	cd_home(void)
{
	char	*path;

	path = ft_strjoin("/home/", getenv("USER"));
	chdir(path);
	free(path);
}

void	cd(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
		i++;
	if (i == 1)
	{
		cd_home();
		return ;
	}
	else if (i > 2)
	{
		ft_printf("cd: too many arguments\n");
		return ;
	}
	chdir(cmd->args[1]);
}
