/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:40:45 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/25 00:05:36 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_simple_exec(t_list *tokens)
{
	if (tokens == NULL)
		return (0);
	while (tokens)
	{
		if (token(tokens)->id == PIPE)
			return (0);
		tokens = tokens->next;
	}
	return (1);
}

static void	dup_and_close(int *redirects)
{
	dup2(redirects[R], STDIN_FILENO);
	dup2(redirects[W], STDOUT_FILENO);
	if (redirects[W] != STDOUT_FILENO)
		close(redirects[W]);
	if (redirects[R] != STDIN_FILENO)
		close(redirects[R]);
}

static int	create_fork(t_token *tkn)
{
	if (ft_streq(tkn->value, "cd"))
		return (BUILTIN_CODE);
	else if (ft_streq(tkn->value, "exit"))
		return (BUILTIN_CODE);
	else if (ft_streq(tkn->value, "pwd"))
		return (BUILTIN_CODE);
	else if (ft_streq(tkn->value, "env"))
		return (BUILTIN_CODE);
	else if (ft_streq(tkn->value, "export"))
		return (BUILTIN_CODE);
	else if (ft_streq(tkn->value, "unset"))
		return (BUILTIN_CODE);
	return (fork());
}

static void	builtin_func(t_list *tokens)
{
	t_command	*command;

	command = new_command(tokens, STDIN_FILENO, STDOUT_FILENO);
	if (ft_streq(command->args[0], "cd"))
		cd(command);
	else if (ft_streq(command->args[0], "exit"))
		exitin(command);
	else if (ft_streq(command->args[0], "pwd"))
		pwd(command);
	else if (ft_streq(command->args[0], "env"))
		env(command);
	else if (ft_streq(command->args[0], "export"))
		export(command);
	else if (ft_streq(command->args[0], "unset"))
		unset(command);
}

void	simple_exec(t_list *tokens)
{
	int		status;
	int		pid;
	int		redirects[2];
	int		err;

	if (!is_simple_exec(tokens))
		return ;
	signal(SIGINT, SIG_IGN);
	err = get_redirects(&tokens, redirects);
	if (in_error() || err || no_command(tokens))
		return ;
	pid = create_fork(token(tokens));
	if (pid == 0)
	{
		set_signals();
		dup_and_close(redirects);
		command_exec(new_command(tokens, STDIN_FILENO, STDOUT_FILENO));
		mini_exit(get_error());
	}
	else if (pid == BUILTIN_CODE)
		return (builtin_func(tokens));
	status = 0;
	waitpid(pid, &status, WUNTRACED);
	set_error(WEXITSTATUS(status));
}
