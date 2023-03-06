/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:10:58 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 02:30:58 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_char(const char *set, char c)
{
	if (ft_strchr(set, c))
		return (1);
	return (0);
}

static int	get_begin_position(char **begin, char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (find_char(set, **begin))
	{
		(*begin)++;
		i++;
		if (i >= ft_strlen(s1))
			return (0);
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*begin;
	char	*end;
	char	*trimmed;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	begin = (char *) s1;
	if (!get_begin_position(&begin, s1, set))
		return (ft_strdup(""));
	end = (char *) &s1[ft_strlen(s1) - 1];
	while (find_char(set, *end))
		end--;
	i = 0;
	while (&begin[i] != end)
		i++;
	i++;
	trimmed = (char *) malloc(i + 1);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, begin, i + 1);
	return (trimmed);
}
