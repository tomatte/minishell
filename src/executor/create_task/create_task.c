/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_task.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:08:23 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/15 20:39:44 by dbrandao         ###   ########.fr       */
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

t_task	*create_task(t_list *tokens, t_list *files)
{
	t_task	*task;

	task = new_task();
	return (task);
}
