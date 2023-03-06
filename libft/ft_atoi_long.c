/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 05:54:21 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 02:31:45 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi_long(const char *nptr)
{
	long int	num;
	int			sign;

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
