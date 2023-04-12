/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evar_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:28:51 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/12 14:42:40 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_evar(t_list *node, char *str)
{
	char	*var;
	int		len;

	var = (char *) node->content;
	len = 0;
	while (var[len] && var[len] != '=')
		len++;
	len = ft_highest(len, ft_strlen(str));
	return (ft_strncmp(var, str, len) == 0);
}

t_list	*find_evar2(char *str)
{
	t_list	*vars;

	if (str == NULL)
		return (NULL);
	vars = get_evars2();
	while (vars)
	{
		if (is_evar(vars, str))
			return (vars);
		vars = vars->next;
	}
	return (NULL);
}

static void	remove_first(t_list	**vars)
{
	t_list	*removed;

	removed = *vars;
	*vars = (*vars)->next;
	ft_lstdelone(removed, free);
}

void	remove_evar(char *str)
{
	t_list	**vars;
	t_list	*aux;
	t_list	*removed;

	vars = evars2();
	removed = NULL;
	if (str == NULL || *vars == NULL)
		return ;
	if (is_evar(*vars, str))
		return (remove_first(vars));
	aux = *vars;
	while (aux->next)
	{
		if (is_evar(aux->next, str))
		{
			removed = aux->next;
			aux->next = removed->next;
			ft_lstdelone(removed, free);
			return ;
		}
		aux = aux->next;
	}
}

char	**get_evars_arr(void)
{
	t_list	*vars;
	int		len;
	char	**arr;
	int		i;

	vars = get_evars2();
	len = ft_lstsize(vars) + 1;
	arr = talloc(len, sizeof(char *));
	i = 0;
	while (vars)
	{
		arr[i] = (char *) vars->content;
		vars = vars->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
