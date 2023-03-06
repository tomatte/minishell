/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:59:22 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/01 21:06:33 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	char	*s;

	s = (char *) src;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	while (i + 1 < size && *s)
	{
		dst[i] = *s;
		s++;
		i++;
	}
	dst[i] = '\0';
	if (dst_len >= size)
		return (size + src_len);
	return (dst_len + src_len);
}
