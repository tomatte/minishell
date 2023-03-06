/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:45:45 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/17 05:00:00 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*n0_set(char **str, t_sign **sign)
{
	char	*aux;
	int		i;
	char	*n0;

	i = (*sign)->dot - ft_strlen(*str);
	if (**str == '-')
		i++;
	if (i <= 0)
		return (ft_strdup(""));
	n0 = (char *) malloc(i + 1);
	if (!n0)
		return (NULL);
	if (**str == '-')
		aux = ft_strdup((*str) + 1);
	else
		aux = ft_strdup((*str));
	if (!aux)
		return (NULL);
	free(*str);
	*str = aux;
	ft_memset((void *) n0, '0', i);
	n0[i] = '\0';
	return (n0);
}

static int	verify_dot(char **str, t_sign **sign, int num)
{
	if ((*sign)->dot == -1)
		return (0);
	if (!(*sign)->dot && !num)
	{
		free(*str);
		*str = ft_strdup("");
		return (0);
	}
	return (1);
}

static void	precision(char **str, t_sign **sign, int num)
{
	char	*n0;
	char	*aux;

	if (!verify_dot(str, sign, num))
		return ;
	n0 = n0_set(str, sign);
	if (!n0)
		return ;
	aux = ft_strjoin(n0, *str);
	if (!aux)
		return ;
	free(n0);
	if (num < 0 && *aux != '-')
	{
		n0 = aux;
		aux = ft_strjoin("-", aux);
		free(n0);
	}
	if (*str)
		free(*str);
	*str = aux;
}

static void	plus_or_space(char **str, int num, t_sign **sign)
{
	char	*aux;

	aux = NULL;
	if (num >= 0 && ((*sign)->plus || (*sign)->spc))
	{
		if ((*sign)->plus)
			aux = ft_strjoin("+", *str);
		else if ((*sign)->spc)
			aux = ft_strjoin(" ", *str);
		if (!aux)
			return ;
		free(*str);
		*str = aux;
	}
}

char	*print_int(t_sign **sign, va_list ap)
{
	char	*str;
	int		num;

	num = va_arg(ap, int);
	str = ft_itoa(num);
	if (!str)
		return (NULL);
	precision(&str, sign, num);
	plus_or_space(&str, num, sign);
	return (str);
}
