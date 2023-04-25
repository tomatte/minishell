/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt_msg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:10:35 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*join_user_host(const char *user, char *host)
{
	char	*user_host;
	int		size;

	if (!host)
		return (ft_strjoin(user, ":"));
	size = ft_strlen(user) + ft_strlen(host) + 3;
	user_host = (char *) malloc(size * sizeof(char));
	ft_strlcpy(user_host, user, size);
	ft_strlcat(user_host, "@", size);
	ft_strlcat(user_host, host, size);
	ft_strlcat(user_host, ":", size);
	return (user_host);
}

static char	*join_with_dir(char *user_host, char *dir)
{
	char	*full;
	int		size;

	size = ft_strlen(user_host) + ft_strlen(dir) + 3;
	full = (char *) malloc(size * sizeof(char));
	ft_strlcpy(full, user_host, size);
	ft_strlcat(full, dir, size);
	ft_strlcat(full, "$ ", size);
	return (full);
}

static void	clean(char *host, char *dir, char *user_host)
{
	if (host)
		free(host);
	free(dir);
	free(user_host);
}

static char	*create_prompt_msg(const char *user, char *host, char *dir)
{
	char	*user_host;
	char	*msg;

	user_host = join_user_host(user, host);
	msg = join_with_dir(user_host, dir);
	clean(host, dir, user_host);
	return (msg);
}

char	*get_prompt_msg(void)
{
	const char	*user;
	char		*host;
	char		*dir;
	char		*msg;

	user = get_username();
	host = get_hostname();
	dir = get_directory(user);
	msg = create_prompt_msg(user, host, dir);
	return (msg);
}
