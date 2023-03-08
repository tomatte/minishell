/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:40:09 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/08 13:20:36 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_operator_id(char *str)
{
	char	*op;
	int		id;

	id = -1;
	while (++id < OP_NUM)
	{
		op = operators()[id];
		if (ft_strncmp(str, op, ft_strlen(op)) == 0)
			return (id);
	}
	return (-1);
}

t_token	*identify_operator(char **str)
{
	char	*value;
	int		id;

	if (*str == NULL)
		return (NULL);
	id = get_operator_id(*str);
	if (id == -1)
		return (NULL);
	value = ft_strdup(operators()[id]);
	(*str) += ft_strlen(value);
	return (new_token(value, OPERATOR, id));
}
