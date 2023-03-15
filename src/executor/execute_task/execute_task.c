/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_task.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:58:34 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/15 16:00:26 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	print_args(t_task *task)
{
	int	i;

	i = 0;
	ft_printf("args: ");
	while (task->args1[i])
	{
		ft_printf("%s  ", task->args1[i]);
		i++;
	}
	ft_printf("\n");
}

void	execute_task(t_task *task)
{
	ft_printf("execute task\n");
	print_args(task);
}
