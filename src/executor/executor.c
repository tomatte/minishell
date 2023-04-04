/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:06:10 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/04 08:13:10 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_files(t_list *files)
{
	t_file	*file;

	while (files)
	{
		file = (t_file *) files->content;
		ft_printf("%d ", file->id);
		files = files->next;
	}
	ft_printf("\n");
}

static int	verify_error(void)
{
	if (in_error())
	{
		ft_printf("EXEC ERROR\n");
		return (1);
	}
	return (0);
}

static t_command	*new_command(t_list *tokens, int fd_in, int fd_out)
{
	t_command	*command;

	command = talloc(1, sizeof(t_command));
	command->args = get_args(tokens);
	command->input_fd = fd_in;
	command->output_fd = fd_out;
	return (command);
}

static void	simple_exec(t_list *tokens)
{
	char	**args;
	int		pid;

	if (tokens == NULL || next_operator(tokens) != NULL)
		return ;
	pid = fork();
	if (pid == 0)
	{
		args = get_args(tokens);
		command_exec(new_command(tokens, STDIN_FILENO, STDOUT_FILENO));
	}
}

static void	wait_childs(void)
{
	int	status;

	status = 0;
	while (wait(&status) != -1)
		;
	if (status)
		set_state(EXEC_ERR);
}

void	executor(t_list *tokens)
{
	t_list	*files;

	if (in_error())
		return ;
	if (tokens == NULL)
		return ;
	files = get_files(tokens);
	simple_exec(tokens);
	pipe_exec(tokens);
	wait_childs();
}
