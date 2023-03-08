/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:15:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/07 21:28:21 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_operator(char *str)
{
	char	*op;
	int		i;	

	if (str == NULL)
		return (0);
	i = -1;
	while (++i < OP_NUM)
	{
		op = operators()[i];
		if (ft_strncmp(str, op, ft_strlen(op)) == 0)
			return (1);
	}
	return (0);
}

void	lexer(char *str)
{
	ft_printf("let's tokenize this: %s\n", str);
}
