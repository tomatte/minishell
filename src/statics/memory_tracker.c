/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_tracker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 07:23:20 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/27 09:08:27 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_list	**memory_tracker(void)
{
	static t_list	*memories = NULL;

	return (&memories);
}

static void	add_to_tracker(void *mem)
{
	t_list	**memories;

	if (mem == NULL)
		return ;
	memories = memory_tracker();
	ft_lstadd_back(memories, ft_lstnew(mem));
}

void	destroy_memories(void)
{
	t_list	**memories;

	memories = memory_tracker();
	ft_lstclear(memories, free);
}

void	*talloc(size_t nmemb, size_t size)
{
	void	*mem;

	mem = ft_calloc(nmemb, size);
	if (mem == NULL)
		return (NULL);
	add_to_tracker(mem);
	return (mem);
}
