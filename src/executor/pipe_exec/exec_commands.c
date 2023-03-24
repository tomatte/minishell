/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:49:23 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/24 11:44:48 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	create_fork(t_list *commands)
{
	t_command	*command;

	command = commands->content;
	command->pid = fork();
}

static void	exec_command(t_pipe *data, int i)
{
	t_command	*command;
	int			*pipedes;

	command = (t_command *) data->commands->content;
	pipedes = data->pipedes[i];
	if (command->pid == 0)
	{
		ft_printf("hello from child %d  pfds: %d,%d\n", i, pipedes[R], pipedes[W]);
		exit(0);
	}
	else
	{
		ft_printf("hello from parent\n");
	}
}

void	exec_commands(t_pipe *data)
{
	int			i;

	i = 0;
	while (data->commands)
	{
		create_fork(data->commands);
		exec_command(data, i);
		data->commands = data->commands->next;
		i++;
	}
	while (wait(NULL) != -1);
}
 