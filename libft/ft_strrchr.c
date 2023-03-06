/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 01:09:09 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/01 21:07:16 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	lc;

	lc = '\0';
	while (*s)
	{
		if (*s == (char) c)
		{
			last = (char *) s;
			lc = *last;
		}
		s++;
	}
	if (lc)
		return (last);
	if (*s == (char) c)
		return ((char *) s);
	return (NULL);
}
