/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:42:01 by dbrandao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/24 22:44:59 by mleonard         ###   ########.fr       */
=======
/*   Updated: 2023/04/24 22:26:30 by dbrandao         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

static void	put_cmd(char **paths, char *cmd)
{
	char	*aux;
	int		i;

	i = -1;
	while (paths[++i])
	{
		aux = paths[i];
		paths[i] = ft_strjoin(paths[i], cmd);
		add_to_tracker(paths[i]);
		free(aux);
	}
}

static char	**split_path(char *path)
{
	char	**paths;

	paths = ft_split(path + ft_strlen(PATH_START), ':');
	add_to_tracker(paths);
	return (paths);
}

char	**get_paths(char *cmd)
{
	char	*path;
	char	**paths;

	path = find_path(get_evars_arr());
	if (path == NULL)
		return (NULL);
	paths = split_path(path);
	put_endslash(paths);
	put_cmd(paths, cmd);
	return (paths);
}
