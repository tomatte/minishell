/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:18:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/20 11:21:53 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_delimiter(char c)
{
	if (ft_strchr(DELIMITER, c))
		return (1);
	if (ft_isspace(c))
		return (1);
	return (0);
}

void	transformer(char *str)
{
	ft_printf("transforming\n");
}