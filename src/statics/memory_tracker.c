/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_tracker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 07:23:20 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/26 11:11:36 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_list	**memory_tracker(void)
{
	static t_list	*memories = NULL;

	return (&memories);
}

void	add_to_tracker(void *mem)
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

t_list	*lstnew_track(void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	add_to_tracker(new);
	return (new);
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
