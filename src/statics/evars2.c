/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evars2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:57:57 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/11 17:28:30 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_list	**evars(void)
{
	static t_list	*vars = NULL;

	return (&vars);
}

void	destroy_evars2(void)
{
	t_list	**vars;

	vars = evars();
	if (*vars == NULL)
		return ;
	ft_lstclear(vars, free);
	*vars = NULL;
}

void	start_evars2(char **envp)
{
	t_list	**vars;
	t_list	*node;
	int		i;

	destroy_evars();
	vars = evars();
	i = -1;
	while (envp[++i] && i < MAX_ENVS)
	{
		node = ft_lstnew(ft_strdup(envp[i]));
		ft_lstadd_back(vars, node);
	}
	
}

t_list	*get_evars2(void)
{
	t_list	**vars;

	vars = evars();
	return (*vars);
}

void	add_evar2(char *str)
{
	t_list	**vars;
	char	*var;

	if (str == NULL)
		return ;
	var = ft_strdup(str);
	vars = evars();
	ft_lstadd_back(vars, ft_lstnew(var));
}
