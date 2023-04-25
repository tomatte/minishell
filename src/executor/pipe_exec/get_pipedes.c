/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipedes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:56:05 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:59 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	get_pipes_len(t_list *tokens)
{
	int	len;

	len = 0;
	while (tokens)
	{
		tokens = next_pipe(tokens);
		if (is_operator(tokens, PIPE))
			len++;
		else
			break ;
	}
	return (len + 1);
}

static int	**alloc_pipes(int len)
{
	int	**pipedes;
	int	i;

	if (len == 0)
		return (NULL);
	pipedes = (int **) talloc(len + 1, sizeof(int *));
	i = -1;
	while (++i < len)
		pipedes[i] = (int *) talloc(2, sizeof(int));
	pipedes[i] = NULL;
	return (pipedes);
}

static void	open_pipes(int **pipedes)
{
	while (*pipedes)
	{
		pipe(*pipedes);
		pipedes++;
	}
}

int	**get_pipedes(t_list *tokens)
{
	int	pipes_len;
	int	**pipedes;

	pipes_len = get_pipes_len(tokens);
	pipedes = alloc_pipes(pipes_len);
	open_pipes(pipedes);
	start_pfds(pipedes);
	return (pipedes);
}
