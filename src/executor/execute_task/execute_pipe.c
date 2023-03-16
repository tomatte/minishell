/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:02:09 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/16 13:38:44 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"


static void	child_code(t_task *task, int pipedes[2][2], int pid)
{
	int	*r_pipe;
	int	*w_pipe;

	if (pid == 0)
	{
		r_pipe = pipedes[0];
		w_pipe = pipedes[1];
		close(r_pipe[1]);
		close(w_pipe[0]);
		dup2(w_pipe[1], STDOUT_FILENO);
		close(w_pipe[1]);
		dup2(r_pipe[0], STDIN_FILENO);
		close(r_pipe[0]);
		execv(task->args[0], task->args);
		exit(-1);
	}
}

static void	parent_code(t_task *task, int pipedes[2][2], int pid)
{
	int	size;
	int	*r_pipe;
	int	*w_pipe;

	if (pid != 0)
	{
		r_pipe = pipedes[1];
		w_pipe = pipedes[0];
		close(r_pipe[1]);
		close(w_pipe[0]);
		size = (ft_strlen(task->value) + 1) * sizeof(char);
		write(w_pipe[1], task->value, size);
		close(w_pipe[1]);
		free(task->value);
		task->value =  NULL;
		waitpid(pid, &(task->status), WUNTRACED);
		if (task->status == 0)
			task->value = read_all(r_pipe[0]);
		close(pipedes[1][0]);
	}
}

void	execute_pipe(t_task *task)
{
	int	pipedes[2][2];
	int	pid;

	if (task->type != PIPE)
		return ;
	pipe(pipedes[0]);
	pipe(pipedes[1]);
	pid = fork();
	parent_code(task, pipedes, pid);
	child_code(task, pipedes, pid);
}
