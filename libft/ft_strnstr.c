/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 04:48:39 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/01 21:07:09 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (!*little)
		return ((char *) big);
	while (i + little_len <= len && big[i])
	{
		if (!ft_strncmp(&big[i], little, little_len))
			return ((char *)(&big[i]));
		i++;
	}
	return (NULL);
}
