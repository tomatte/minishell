/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:59:59 by dbrandao          #+#    #+#             */
/*   Updated: 2022/07/19 05:30:04 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_sign(t_sign **sign)
{
	(*sign)->minus = 0;
	(*sign)->zero = 0;
	(*sign)->dot = -1;
	(*sign)->ht = 0;
	(*sign)->spc = 0;
	(*sign)->plus = 0;
	(*sign)->type = 0;
	(*sign)->fill = 0;
	(*sign)->is_valid = 1;
}

void	is_digit_alone(const char *str, t_sign **sign, int *index, int *c)
{
	int	i;
	int	n;

	if (!ft_isdigit(*str))
		return ;
	n = 0;
	i = -1;
	while (ft_isdigit(str[++i]))
		n = (n * 10) + str[i] - 48;
	if (!ft_strchr(".+", str[i]) && !ft_strchr(CONVERSION, str[i]))
		(*sign)->is_valid = 0;
	if (*str == '0')
		(*sign)->zero = n;
	else
		(*sign)->fill = n;
	if (*str == '0' && n == 0 && ft_strchr("-#", str[i]))
		(*sign)->is_valid = 1;
	(*index) += i;
	*c = str[i];
	if (ft_strchr(CONVERSION, str[i]) && str[i])
		(*sign)->type = str[i];
}

void	dot_case(const char *str, t_sign **sign, int c, int *index)
{
	int	i;
	int	n;

	if (c != '.')
		return ;
	str++;
	if ((!ft_isdigit(*str) && !ft_strchr("diuxXscp", *str)) || !*str)
		(*sign)->is_valid = 0;
	n = 0;
	i = -1;
	while (ft_isdigit(str[++i]))
		n = (n * 10) + str[i] - 48;
	if (!ft_strchr("diuxXscp", str[i]) || !*str)
	{
		(*sign)->is_valid = 0;
		return ;
	}
	*index += i + 1;
	(*sign)->type = str[i];
	(*sign)->dot = n;
}

void	sign_place(t_sign **sign, int c)
{
	if (((*sign)->dot >= 0 || (*sign)->zero) && (*sign)->is_valid)
		return ;
	if (ft_strchr(CONVERSION, c))
	{
		(*sign)->type = c;
		(*sign)->is_valid = 1;
	}
	else if (!ft_strchr(FORMAT, c))
		(*sign)->is_valid = 0;
	else if (c == '-')
		(*sign)->minus = 1;
	else if (c == '#')
		(*sign)->ht = 1;
	else if (c == ' ')
		(*sign)->spc = 1;
	else if (c == '+')
		(*sign)->plus = 1;
}

char	*set_n0(char **str, t_sign **sign)
{
	char	*aux;
	int		i;
	char	*n0;

	i = (*sign)->dot - ft_strlen(*str);
	if (**str == '-')
		i--;
	if (i <= 0)
		return (NULL);
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
