/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_task.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:58:34 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/15 18:00:00 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	print_args(t_task *task)
{
	int	i;

	i = 0;
	ft_printf("args: ");
	while (task->args[i])
	{
		ft_printf("%s  ", task->args[i]);
		i++;
	}
	ft_printf("\n");
}

void	execute_task(t_task *task)
{
	//execute_command(); criar função
	ft_printf("execute task\n");
	print_args(task);
}
