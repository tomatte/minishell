/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:40:45 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/05 10:44:00 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	simple_exec(t_list *tokens)
{
	int		pid;

	if (tokens == NULL || next_operator(tokens) != NULL)
		return ;
	pid = fork();
	if (pid == 0)
	{
		command_exec(new_command(tokens, STDIN_FILENO, STDOUT_FILENO));
	}
}
