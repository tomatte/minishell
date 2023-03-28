/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:11:57 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/28 15:28:41 by dbrandao         ###   ########.fr       */
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
	ft_lstadd_back(vars, lstnew_track(var));
}

void	start_evars(char **envp)
{
	t_list	**vars;

	vars = evars();
	while (*envp)
		ft_lstadd_back(vars, lstnew_track(*envp++));
}
