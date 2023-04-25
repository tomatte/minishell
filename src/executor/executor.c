/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:06:10 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	executor(t_list *tokens)
{
	if (in_error())
		return ;
	if (tokens == NULL)
		return ;
	simple_exec(tokens);
	pipe_exec(tokens);
}
