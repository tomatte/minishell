/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:03:39 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/15 19:08:14 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	child_code(int pid, int *pipedes, t_task *task)
{
	if (pid == 0)
	{
		close(pipedes[0]);
		dup2(pipedes[1], STDOUT_FILENO);
		close(pipedes[1]);
		execv(task->args[0], task->args);
	}
}

static void	parent_code(int pid, int *pipedes, t_task *task)
{
	if (pid != 0)
	{
		close(pipedes[1]);
		wait(NULL);
		task->value = read_all(pipedes[0]);
		close(pipedes[0]);
		task->type = NEXT;
	}
}

void	execute_command(t_task *task)
{
	int	pipedes[2];
	int	pid;

	if (task->type != EXEC)
		return ;
	pipe(pipedes);
	pid = fork();
	child_code(pid, pipedes, task);
	parent_code(pid, pipedes, task);
}
