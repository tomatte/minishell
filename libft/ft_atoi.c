/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:54:21 by dbrandao          #+#    #+#             */
/*   Updated: 2022/10/27 18:11:10 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign *= -1;
	if (ft_issign(*nptr))
		nptr++;
	while (ft_isdigit(*nptr))
	{
		num = num * 10 + (*nptr - 48);
		nptr++;
	}
	return (num * sign);
}
