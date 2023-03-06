/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_zeros.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 04:51:09 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/17 05:06:51 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	verifications(t_sign **sign)
{
	if ((*sign)->minus)
	{
		if ((*sign)->zero > (*sign)->fill)
		{
			(*sign)->fill = (*sign)->zero;
			(*sign)->zero = 0;
		}
	}
	if ((*sign)->dot != -1 && (*sign)->zero && (*sign)->zero > (*sign)->fill)
	{
		(*sign)->fill = (*sign)->zero;
		(*sign)->zero = 0;
	}
}

static char	*fill_zero_aux(char **str, t_sign **sign)
{
	char	*fill;
	char	*aux;
	int		zeros;

	zeros = (*sign)->zero - ft_strlen(*str);
	if (**str == '-' && ((*sign)->type == 'd' || (*sign)->type == 'i'))
		zeros++;
	fill = (char *) malloc(zeros + 1);
	if (!fill)
		return (NULL);
	ft_memset(fill, 0, zeros + 1);
	if (**str == '-' && ((*sign)->type == 'd' || (*sign)->type == 'i'))
	{
		*fill = '-';
		ft_memset(fill + 1, '0', zeros - 1);
		aux = *str;
		*str = ft_strtrim(*str, "-");
		free(aux);
		if (!*str || !fill)
			return (NULL);
	}
	else
		ft_memset(fill, '0', zeros);
	return (fill);
}

void	fill_zeros(char **str, t_sign **sign)
{
	char	*fill;
	char	*aux;

	if ((!(*sign)->fill && !(*sign)->zero) || !*str)
		return ;
	verifications(sign);
	if ((*sign)->zero > (int) ft_strlen(*str))
	{
		fill = fill_zero_aux(str, sign);
		if (!fill || !*str)
			return ;
		aux = *str;
		*str = ft_strjoin(fill, *str);
		free(aux);
		free(fill);
	}
}
