/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:00:02 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/24 16:24:46 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	del_command(void *mem)
{
	t_command	*command;

	command = (t_command *) mem;
	free(command->args);
	free(command);
}

static void	clear_data(t_list *commands, int **pipedes)
{
	int	i;

	i = 0;
	while (pipedes[i])
		free(pipedes[i++]);
	free(pipedes);
	ft_lstclear(&commands, del_command);
}

void	pipe_exec(t_list *tokens, char **envp)
{
	t_list	*commands;
	int		**pipedes;

	if (!is_operator(tokens, PIPE))
		return ;
	pipedes = get_pipedes(tokens);
	commands = get_commands(tokens, pipedes);
	exec_commands(commands, pipedes, envp);
	close_pipes(pipedes);
	clear_data(commands, pipedes);
}
