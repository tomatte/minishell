/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:09:49 by dbrandao          #+#    #+#             */
/*   Updated: 2022/06/29 22:34:10 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	verify_line(char **storage, char **single_line)
{
	if (!*storage)
		return (0);
	if (!find_chr(storage, '\n'))
		return (0);
	*single_line = strdup_flex(*storage, '\n', NULL);
	if (!*single_line)
		return (-1);
	remove_first_line(storage);
	return (1);
}

void	store_in_static(char **storage, char *buffer, ssize_t b_size)
{
	char	*new;

	new = m_join(*storage, buffer, b_size);
	if (!new)
		return ;
	free(*storage);
	*storage = new;
}

int	no_return(char *storage, char *buffer, ssize_t r_bytes)
{
	if (r_bytes < 0)
	{
		free(buffer);
		return (-1);
	}
	if (!storage && !r_bytes)
	{
		free(buffer);
		return (0);
	}
	if (storage && !r_bytes)
	{
		free(buffer);
		return (2);
	}
	return (1);
}

int	read_buffer(int fd, char **storage, char **s_line)
{
	char	*buffer;
	int		r_bytes;
	int		flag;

	buffer = (char *) malloc(BUFFER_SIZE);
	if (!buffer)
		return (0);
	while (1)
	{
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		flag = no_return(*storage, buffer, r_bytes);
		if (flag != 1)
			return (flag);
		store_in_static(storage, buffer, r_bytes);
		flag = verify_line(storage, s_line);
		if (flag)
		{
			free(buffer);
			return (flag);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*single_line;
	int			flag;

	if (!storage[fd])
		storage[fd] = NULL;
	flag = verify_line(&storage[fd], &single_line);
	if (flag == 1)
		return (single_line);
	else if (flag == -1)
		return (NULL);
	flag = read_buffer(fd, &storage[fd], &single_line);
	if (flag == 1)
		return (single_line);
	else if (flag == 2)
	{
		single_line = strdup_flex(storage[fd], '\0', NULL);
		del(&storage[fd]);
		if (!single_line)
			return (NULL);
		return (single_line);
	}
	if (storage[fd])
		del(&storage[fd]);
	return (NULL);
}
