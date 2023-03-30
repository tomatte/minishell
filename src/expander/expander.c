/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:30:03 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/30 02:04:22 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	expander(char **str)
{
	t_exp	exp;

	fill_exp(&exp, *str);
	ft_printf("v: %s  l: %d\n", exp.value, exp.len);
}
