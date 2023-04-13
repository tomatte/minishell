/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:06:10 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/13 15:08:09 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	verify_error(void)
{
	if (in_error())
	{
		ft_printf("EXEC ERROR\n");
		return (1);
	}
	return (0);
}

static void	wait_childs(void)
{
	int	status;
	int	i;

	i = 0;
	while (wait(&status) != -1)
		i++;
	if (i == 0)
		return ;
	set_state(status);
	set_error(status);
}

void	executor(t_list *tokens)
{
	if (in_error())
		return ;
	if (tokens == NULL)
		return ;
	simple_exec(tokens);
	pipe_exec(tokens);
	wait_childs();
}
