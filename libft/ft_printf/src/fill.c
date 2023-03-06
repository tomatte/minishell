/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 04:46:15 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/17 05:05:59 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_spaces(char **str, t_sign **sign)
{
	char	*fill;
	char	*aux;
	int		len;

	len = ft_strlen(*str);
	if ((*sign)->fill > len)
	{
		fill = (char *) malloc((*sign)->fill - len + 1);
		if (!fill)
			return ;
		ft_memset(fill, ' ', (*sign)->fill - len);
		fill[(*sign)->fill - len] = '\0';
		aux = *str;
		if ((*sign)->minus)
			*str = ft_strjoin(*str, fill);
		else
			*str = ft_strjoin(fill, *str);
		free(aux);
		free(fill);
	}
}

void	fill_c(char **str, t_sign **sign)
{
	int		size;

	size = (*sign)->fill;
	if (size < 2)
		return ;
	(*str) = (char *) malloc(size);
	if (!(*str))
		return ;
	ft_memset((*str), ' ', size - 1);
	(*str)[size - 1] = '\0';
	(*sign)->fill = 0;
}

void	fill(char **str, t_sign **sign)
{
	if ((!(*sign)->fill && !(*sign)->zero) || !*str)
		return ;
	fill_spaces(str, sign);
}
