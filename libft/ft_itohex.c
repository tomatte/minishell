/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 04:59:47 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/05 02:47:47 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_len(long unsigned int number)
{
	int	i;

	if (!number)
		return (1);
	i = 0;
	while (number)
	{
		number /= 16;
		i++;
	}
	return (i);
}

char	*ft_itohex(long unsigned int number)
{
	char		*hexnumber;
	int			remainder;
	int			len;

	len = hex_len(number);
	hexnumber = (char *) malloc(sizeof(char) * len + 1);
	if (!hexnumber)
		return (NULL);
	hexnumber[len] = '\0';
	remainder = 1;
	while (len--)
	{
		remainder = number % 16;
		number = number / 16;
		hexnumber[len] = HEXMAP[remainder];
	}
	return (hexnumber);
}
