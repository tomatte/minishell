/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:05:41 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/14 10:30:44 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

int	ft_pow(int num, int power)
{
	int	i;
	int	result;

	if (!power)
		return (1);
	result = 1;
	i = 0;
	while (i++ < power)
	{
		result *= num;
	}
	return (result);
}
