/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_task.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:08:23 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/16 10:30:37 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static t_task	*new_task(void)
{
	t_task	*task;

	task = (t_task *) malloc(sizeof(t_task));
	ft_bzero(task, sizeof(t_task));
	return (task);
}

void	fill_task(t_task **task, t_list *tokens, t_list *files)
{
	if (*task == NULL)
		*task = new_task();
	command_task(*task, tokens);
}
