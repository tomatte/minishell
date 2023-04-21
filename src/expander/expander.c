/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:30:03 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/21 16:51:26 by dbrandao         ###   ########.fr       */
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
