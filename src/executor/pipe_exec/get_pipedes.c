/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipedes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:56:05 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/23 16:00:10 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	get_pipes_len(t_list *tokens)
{
	int	len;

	len = 0;
	while (tokens)
	{
		tokens = next_operator(tokens);
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
	pipedes = (int **) malloc(sizeof(int *) * (len + 1));
	i = -1;
	while (++i < len)
		pipedes[i] = (int *) malloc(sizeof(int) * 2);
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

static void	print_pipedes(int **pipedes)
{
	while (*pipedes)
	{
		ft_printf("r%d / w%d\n", (*pipedes)[0], (*pipedes)[1]);
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
	return (pipedes);
}
