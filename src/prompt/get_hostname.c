/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hostname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:17:49 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_hostname(void)
{
	int		fd;
	char	*hostname;
	char	*aux;

	fd = open("/etc/hostname", O_RDONLY);
	if (fd == -1)
		return (NULL);
	aux = get_next_line(fd);
	hostname = ft_strtrim(aux, " \n\t");
	free(aux);
	close(fd);
	return (hostname);
}
