/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_pipe_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:46:17 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/24 09:47:34 by dbrandao         ###   ########.fr       */
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

void	clear_pipe_data(t_pipe *data)
{
	int	i;

	i = 0;
	while (data->pipedes[i])
		free(data->pipedes[i++]);
	free(data->pipedes);
	ft_lstclear(&(data->commands), del_command);
}
