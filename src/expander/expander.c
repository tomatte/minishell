/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:30:03 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/20 11:21:45 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	verify_unclosed_quotes(char *str)
{
	int	simple_quotes;
	int	double_quotes;

	if (str == NULL)
		return ;
	simple_quotes = 1;
	double_quotes = 1;
	while (*str)
	{
		if (*str == '\'' && double_quotes != -1)
			simple_quotes *= -1;
		if (*str == '"' && simple_quotes != -1)
			double_quotes *= -1;
		str++;
	}
	if (simple_quotes == -1 || double_quotes == -1)
	{
		set_error(33);
		set_state(-1);
		ft_putstr_fd("syntax error: unclosed quotes\n", 2);
	}
}

static void	remove_quotes(char *str)
{
	char	*dst;
	int		i;
	int	simple_quotes;
	int	double_quotes;

	if (str == NULL)
		return ;
	simple_quotes = 1;
	double_quotes = 1;
	dst  = str;
	i = 0;
	while (*str)
	{
		if (*str == '\'' && double_quotes != -1)
			simple_quotes *= -1;
		if (*str == '"' && simple_quotes != -1)
			double_quotes *= -1;
		while (*str == '\'' && double_quotes != -1)
			str++;
		while (*str == '"' && simple_quotes != -1)
			str++;
		dst[i] = *str;
		i++;
		str++;
	}
	dst[i] = '\0';
}

void	expander(char **str)
{
	t_exp	exp;

	set_state(0);
	while (1)
	{
		fill_exp(&exp, *str);
		fill_exp_value(&exp);
		expand_str(str, &exp);
		if (exp.start == NULL)
			break ;
	}
	verify_unclosed_quotes(*str);
}


/* 

[", a, b, c, d, a, "]
ab"c"

uva|"passas" roxa

mover a aspa de abertura pro inicio da palavra

mover a aspa de fechamento pro final da palavra

start = "

 */