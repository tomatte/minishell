/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:11:57 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/28 15:43:36 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_list	**evars(void)
{
	static t_list	*vars = NULL;

	return (&vars);
}

t_list	*get_evars(void)
{
	t_list	**vars;

	vars = evars();
	return (*vars);
}

void	add_evar(char *var)
{
	t_list	**vars;

	vars = evars();
	ft_lstadd_back(vars, ft_lstnew(var));
}

void	start_evars(char **envp)
{
	t_list	**vars;
	int		i;

	vars = evars();
	i = -1;
	while (envp[++i])
		ft_lstadd_back(vars, ft_lstnew(ft_strdup(envp[i])));
}

void	destroy_evars(void)
{
	t_list	**vars;

	vars = evars();
	ft_lstclear(vars, free);
}
