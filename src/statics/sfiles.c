/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:45:32 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 18:49:55 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_list	**fd_list(void)
{
	static t_list	*fds = NULL;

	return (&fds);
}

void	add_fd(int fd)
{
	t_list	**fds;
	int		*new_fd;

	fds = fd_list();
	new_fd = ft_calloc(1,  sizeof(int));
	*new_fd = fd;
	ft_lstadd_back(fds, ft_lstnew(new_fd));
}

void	close_fds(void)
{
	t_list	**fds;
	t_list	*aux;

	fds = fd_list();
	if (*fds == NULL)
		return ;
	aux= *fds;
	while (aux)
	{
		close(*((int *) aux->content));
		aux = aux->next;
	}
	ft_lstclear(fds, free);
	*fds = NULL;
}
