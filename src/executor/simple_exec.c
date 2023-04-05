/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:40:45 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/05 11:03:49 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_simple_exec(t_list *tokens)
{
	if (tokens == NULL)
		return (0);
	if (next_operator(tokens) == NULL)
		return (1);
	while (is_redirect(next_operator(tokens)))
		tokens = next_operator(tokens);
	if (next_operator(tokens) == NULL)
		return (1);
	return (0);
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

void	simple_exec(t_list *tokens)
{
	int		pid;
	int		redirects[2];

	if (!is_simple_exec(tokens))
		return ;
	pid = fork();
	if (pid == 0)
	{
		get_redirects(tokens, redirects);
		dup_and_close(redirects);
		command_exec(new_command(tokens, STDIN_FILENO, STDOUT_FILENO));
	}
}
