/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_exp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:02:50 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/21 18:50:06 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	pass_simple_quotes(char **str)
{
	(*str)++;
	while (**str && **str != 39)
		(*str)++;
	if (**str)
		(*str)++;
}

static void	find_start(char *str, t_exp *exp)
{
	int	double_quotes;

	double_quotes = -1;
	while (*str)
	{
		if (*str == '"')
			double_quotes *= -1;
		if (*str == '\'' && double_quotes != 1)
			pass_simple_quotes(&str);
		if (!*str || *str == '$')
		{
			if (!ft_strchr(EXP_DELIMITER, *(str + 1)))
				break ;
		}
		str++;
	}
	if (*str)
		exp->start = str + 1;
	else
		exp->start = NULL;
}

static void	find_end(t_exp *exp)
{
	char	*str;
	int		len;

	if (exp->start == NULL)
		return ;
	len = 0;
	str = exp->start;
	while (str && !ft_strchr(EXP_DELIMITER, *str))
	{
		str++;
		len++;
		if (*(exp->start) == '?')
			break ;
	}
	exp->end = str;
	exp->len = len;
}

static void	fill_name(t_exp *exp)
{
	char	*name;

	if (exp->start == NULL)
		return ;
	name = talloc(exp->len + 1, sizeof(char));
	ft_strlcpy(name, exp->start, exp->len + 1);
	exp->name = name;
}

void	fill_exp(t_exp *exp, char *str)
{
	find_start(str, exp);
	find_end(exp);
	fill_name(exp);
}
