/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipedes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:56:05 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/22 11:25:42 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	pipes_len(t_list *tokens)
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
	return (len);
}

int	**get_pipedes(t_list *tokens)
{
	int	len;

	len = pipes_len(tokens);
	ft_printf("pipes len: %d\n", len);
	return (NULL);
}
