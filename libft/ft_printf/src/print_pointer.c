/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:46:07 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/18 22:13:19 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision(char **str, t_sign **sign, long unsigned int num)
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

static char	*number_tohex(long unsigned int number, t_sign **sign)
{
	char	*ptr;

	ptr = ft_itohex(number);
	if (!ptr)
		return (NULL);
	precision(&ptr, sign, number);
	return (ptr);
}

char	*print_pointer(t_sign **sign, va_list ap)
{
	char				*ptr;
	char				*aux;
	long unsigned int	address;

	address = va_arg(ap, long unsigned);
	if (!address)
		return (ft_strdup("(nil)"));
	ptr = number_tohex(address, sign);
	aux = ptr;
	ptr = ft_strjoin("0x", ptr);
	if (!ptr)
		return (NULL);
	free(aux);
	if ((*sign)->plus || (*sign)->spc)
	{
		aux = ptr;
		if ((*sign)->plus)
			ptr = ft_strjoin("+", ptr);
		else if ((*sign)->spc)
			ptr = ft_strjoin(" ", ptr);
		if (!ptr)
			return (NULL);
		free(aux);
	}
	return (ptr);
}
