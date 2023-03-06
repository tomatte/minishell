/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:27:38 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/04 05:02:07 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int n, int pwr)
{
	int	result;

	result = 1;
	while (pwr--)
		result *= n;
	return (result);
}

static int	decimal_count(int n)
{
	int	i;

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

static void	negative_case(int *n, int fd)
{
	if (*n < 0)
	{
		if (*n == -2147483648)
		{
			write(fd, "-2", 2);
			*n += 2000000000;
			*n *= -1;
		}
		else
		{
			write(fd, "-", 1);
			*n *= -1;
		}
	}
}

/*
logic in loop:
	pow = 10 ^ (dp - 1)
	n = number / pow
	write(n);
	number -= n * pow;
	dp--;
*/
void	ft_putnbr_fd(int n, int fd)
{
	int	decimal_places;
	int	pow;
	int	unit;

	negative_case(&n, fd);
	decimal_places = decimal_count(n);
	while (decimal_places)
	{
		pow = ft_power(10, decimal_places - 1);
		unit = n / pow;
		ft_putchar_fd(unit + 48, fd);
		n -= unit * pow;
		decimal_places--;
	}
}
