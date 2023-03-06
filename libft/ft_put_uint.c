/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:39:43 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/01 23:53:54 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_power(unsigned int n, unsigned int pwr)
{
	unsigned int	result;

	result = 1;
	while (pwr--)
		result *= n;
	return (result);
}

static unsigned int	decimal_count(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (1);
	else
	{
		while (n)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

void	ft_put_uint(unsigned int n)
{
	unsigned int	decimal_places;
	unsigned int	pow;
	unsigned int	unit;

	decimal_places = decimal_count(n);
	while (decimal_places)
	{
		pow = ft_power(10, decimal_places - 1);
		unit = n / pow;
		ft_putchar(unit + 48);
		n -= unit * pow;
		decimal_places--;
	}
}
