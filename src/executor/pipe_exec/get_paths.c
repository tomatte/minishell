/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:42:01 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/26 21:25:04 by dbrandao         ###   ########.fr       */
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

static void	put_endslash(char **paths)
{
	char	*aux;
	int		i;

	i = -1;
	while (paths[++i])
	{
		aux = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(aux);
	}
}

static void	put_cmd(char **paths,  char *cmd)
{
	char	*aux;
	int		i;

	i = -1;
	while (paths[++i])
	{
		aux = paths[i];
		paths[i] = ft_strjoin(paths[i], cmd);
		free(aux);
	}
}

void	clear_paths(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

char	**get_paths(char **envp, char *cmd)
{
	char	*path;
	char	**paths;

	path = find_path(envp);
	paths = ft_split(path + ft_strlen(PATH_START), ':');
	put_endslash(paths);
	put_cmd(paths, cmd);
	return (paths);
}
