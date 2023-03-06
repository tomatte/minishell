/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:31:38 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/01 21:04:15 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*aux;

	if (!lst || !f)
		return (NULL);
	first = ft_lstnew(f(lst->content));
	if (!first)
		return (NULL);
	aux = first;
	while (lst->next)
	{
		aux->next = ft_lstnew(f(lst->next->content));
		if (!aux->next)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		aux = aux->next;
		lst = lst->next;
	}
	return (first);
}
