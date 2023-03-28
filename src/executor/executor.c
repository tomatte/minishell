/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:06:10 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/28 14:45:52 by dbrandao         ###   ########.fr       */
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

static void	try_execve(char **args, char **envp)
{
	char	**paths;
	char	*cmd;
	int		i;

	cmd = args[0];
	execve(cmd, args, envp);
	paths = get_paths(envp, cmd);
	i = -1;
	while (paths[++i])
	{
		args[0] = paths[i];
		execve(args[0], args, envp);
	}
	args[0] = cmd;
}

static void	exit_error(char **args)
{
	ft_printf("error executing command %s\n", args[0]);
	close(R);
	close(W);
	destroy_memories();
	clear_history();
	exit(1);
}

static void	command_exec(t_list *tokens, char **envp)
{
	char	**args;
	int		pid;

	if (next_operator(tokens) != NULL)
		return ;
	pid = fork();
	if (pid == 0)
	{
		args = get_args(tokens);
		try_execve(args, envp);
		exit_error(args);
	}
}

void	executor(t_list *tokens, char **envp)
{
	t_list	*files;

	if (in_error())
		return ;
	files = get_files(tokens);
	command_exec(tokens, envp);
	pipe_exec(tokens, envp);
	while (wait(NULL) != -1)
		;
}
