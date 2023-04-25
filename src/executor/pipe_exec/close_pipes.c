/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:04:37 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:59 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	close_pipes(int **pipedes)
{
	while (*pipedes)
	{
		if ((*pipedes)[R] != STDIN_FILENO)
			close((*pipedes)[R]);
		if ((*pipedes)[W] != STDOUT_FILENO)
			close((*pipedes)[W]);
		pipedes++;
	}
}
