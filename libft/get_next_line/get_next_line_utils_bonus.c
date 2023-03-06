/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:09:26 by dbrandao          #+#    #+#             */
/*   Updated: 2022/06/29 22:09:28 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*strdup_flex(char	*str, char end, char *mem)
{
	int		i;
	char	*dup;

	i = 0;
	while ((str[i] != end && str[i] && end != -1) || (&str[i] != mem && mem))
		i++;
	if (str[i])
		i++;
	dup = (char *) malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while ((str[i] != end && str[i] && end != -1) || (&str[i] != mem && mem))
	{
		dup[i] = str[i];
		i++;
	}
	if (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*find_chr(char **str, char c)
{
	int	i;

	i = 0;
	while ((*str)[i] != c && (*str)[i])
		i++;
	if ((*str)[i] == c)
		return (&(*str)[i]);
	return (NULL);
}

char	*m_join(char *s1, char *buff, ssize_t b_size)
{
	int		i;
	int		j;
	char	*new;

	if (!s1)
	{
		new = strdup_flex(buff, -1, &buff[b_size - 1]);
		if (!new)
			return (NULL);
		return (new);
	}
	i = 0;
	while (s1[i])
		i++;
	new = (char *) malloc(i + b_size + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (++j < b_size)
		new[i + j] = buff[j];
	new[i + j] = '\0';
	return (new);
}

void	del(char	**mem)
{
	free(*mem);
	*mem = NULL;
}

void	remove_first_line(char **storage)
{
	char	*begin;
	char	*new;
	int		i;

	begin = find_chr(storage, '\n');
	begin++;
	if (!*begin)
	{
		del(storage);
		return ;
	}
	i = 0;
	while (begin[i])
		i++;
	new = (char *) malloc(i + 1);
	if (!new)
		return ;
	i = -1;
	while (begin[++i])
		new[i] = begin[i];
	new[i] = '\0';
	free(*storage);
	*storage = new;
}
