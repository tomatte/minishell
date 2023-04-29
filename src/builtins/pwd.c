/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:30:52 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/29 18:26:06 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	pwd(t_command *cmd)
{
	char	*dir;

	if (is_option(cmd->args[1]))
	{
		invalid_option(cmd->args[0], cmd->args[1]);
		return ;
	}
	dir = talloc(256, sizeof(char));
	getcwd(dir, 256);
	if (dir == NULL)
	{
		ft_putstr_fd("pwd: too big directory name\n", STDERR_FILENO);
		set_error(5);
	}
	else
	{
		ft_putstr(dir);
		ft_putchar('\n');
	}
	set_error(0);
}
