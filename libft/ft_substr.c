/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:12:54 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/01 21:07:39 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	start_size;
	char	*substr;

	if (!s || ft_strlen(s) < start + 1)
		return (ft_strdup(""));
	start_size = ft_strlen(&s[start]);
	if (start_size < len)
		len = start_size;
	substr = ((char *) malloc(len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}
