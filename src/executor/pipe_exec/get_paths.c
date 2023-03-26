/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:42:01 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/26 19:57:28 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*find_path(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(PATH_START, envp[i], ft_strlen(PATH_START)) == 0)
			break ;
	}
	return (envp[i]);
}

char	**get_paths(char **envp)
{
	char	*path;
	char	**paths;

	path = find_path(envp);
	paths = ft_split(path + ft_strlen(PATH_START), ':');
	return (paths);
}
