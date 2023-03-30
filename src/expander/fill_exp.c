/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_exp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:02:50 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/30 02:04:49 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	pass_simple_quotes(char **str)
{
	(*str)++;
	while (**str != 39)
		(*str)++;
	if ((*str))
		(*str)++;
}

static void	find_start(char *str, t_exp *exp)
{
	int	double_quotes;

	double_quotes = -1;
	while (str)
	{
		if (*str == '"')
			double_quotes *= -1;
		if (*str == '\'' && double_quotes != 1)
			pass_simple_quotes(&str);
		if (*str == '$')
			break ;
		str++;
	}
	exp->start = str;
}

static void	find_end(t_exp *exp)
{
	char	*str;
	int		len;

	if (exp->start == NULL)
		return ;
	len = 0;
	str = exp->start + 1;
	while (str && !ft_strchr(EXP_DELIMITER, *str))
	{
		str++;
		len++;
	}
	exp->end = str;
	exp->len = len;
}

static void	fill_value(t_exp *exp)
{
	char	*value;

	value = ft_calloc(exp->len + 1, sizeof(char));
	ft_strlcpy(value, exp->start + 1, exp->len + 1);
	exp->value = value;
}

void	fill_exp(t_exp *exp, char *str)
{
	find_start(str, exp);
	find_end(exp);
	fill_value(exp);
}
