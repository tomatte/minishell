/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:30:03 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/30 10:41:03 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	expander(char **str)
{
	t_exp	exp;

	fill_exp(&exp, *str);
	fill_exp_value(&exp);
	expand_str(str, &exp);
	ft_printf("RESULT: %s\n", *str);
}
