/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:42:18 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/18 22:24:55 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	actions(char **hex, t_sign **sign, char type, long unsigned num)
{
	char	*aux;

	if ((*sign)->ht && num)
	{
		aux = *hex;
		*hex = ft_strjoin("0x", *hex);
		if (!*hex)
			return ;
		free(aux);
	}
	if (type == 'X')
		ft_strtoupper(*hex);
}

static void	precision(char **str, t_sign **sign, unsigned int num)
{
	char	*n0;
	char	*aux;

	if ((*sign)->dot == -1)
		return ;
	if (!(*sign)->dot && !num)
	{
		free(*str);
		*str = ft_strdup("");
		return ;
	}
	n0 = set_n0(str, sign);
	if (!n0)
		return ;
	aux = ft_strjoin(n0, *str);
	if (!aux)
		return ;
	free(n0);
	if (*str)
		free(*str);
	*str = aux;
}

char	*print_hex(t_sign **sign, va_list ap, char type)
{
	char			*hex;
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	hex = ft_itohex(num);
	precision(&hex, sign, num);
	actions(&hex, sign, type, num);
	return (hex);
}
