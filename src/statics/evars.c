/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:11:57 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/29 09:35:15 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	***evars(void)
{
	static char	**vars = NULL;

	return (&vars);
}

char	**get_evars(void)
{
	char	***vars;

	vars = evars();
	return (*vars);
}

void	add_evar(char *var)
{
	char	***vars;
	int		i;

	vars = evars();
	i = 0;
	while ((*vars)[i] && i < MAX_ENVS)
		i++;
	if (i == MAX_ENVS)
		return ;
	(*vars)[i] = var;
	(*vars)[i + 1] = NULL;
}

void	destroy_evars(void)
{
	char	***vars;
	int		i;

	vars = evars();
	if (*vars == NULL)
		return ;
	i = -1;
	while ((*vars)[++i])
		free((*vars)[i]);
	free(*vars);
	*vars = NULL;
}

void	start_evars(char **envp)
{
	char	***vars;
	int		i;

	destroy_evars();
	vars = evars();
	*vars = ft_calloc(MAX_ENVS, sizeof(char *));
	i = -1;
	while (envp[++i] && i < MAX_ENVS)
		(*vars)[i] = ft_strdup(envp[i]);
	(*vars)[i] = NULL;
}
