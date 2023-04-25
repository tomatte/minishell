/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:32:14 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	in_home(char *dir)
{
	if (ft_strncmp(dir, "/home", 5) == 0)
		return (1);
	return (0);
}

static int	in_user(char *dir, const char *user)
{
	size_t	size;
	size_t	jump;

	jump = 6;
	if (ft_strlen(dir) <= jump)
		return (0);
	size = ft_strlen(user);
	if (ft_strncmp(dir + jump, user, size) == 0)
		return (1);
	return (0);
}

static void	put_tilde(char **dir, const char *username)
{
	char	*directory;
	char	*aux;
	int		jump;

	directory = *dir;
	if (!directory)
		return ;
	if (!in_home(directory) || !in_user(directory, username))
		return ;
	aux = directory;
	jump = ft_strlen("/home") + ft_strlen(username) + 1;
	directory = ft_strjoin("~", directory + jump);
	free(aux);
	*dir = directory;
}

char	*get_directory(const char *username)
{
	char	*directory;

	directory = getcwd(NULL, 0);
	put_tilde(&directory, username);
	return (directory);
}
