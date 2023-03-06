/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 07:04:06 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/11 19:03:43 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(unsigned int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*s_num;
	int		len;

	len = num_len(n);
	s_num = (char *) malloc(sizeof(char) * len + 1);
	if (!s_num)
		return (NULL);
	s_num[len] = '\0';
	while (--len >= 0)
	{
		s_num[len] = (n % 10) + 48;
		n /= 10;
	}
	return (s_num);
}
