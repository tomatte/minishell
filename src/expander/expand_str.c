/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:28:05 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/21 18:43:29 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_strsize(char *str, t_exp *exp)
{
	int		size;

	size = 0;
	while (str != exp->start - 1)
	{
		str++;
		size++;
	}
	size += ft_strlen(exp->end);
	size += ft_strlen(exp->value);
	return (size + 1);
}

static void	replace_str(char **str, t_exp *exp, int size)
{
	char	*new;
	int		len;

	new = talloc(size, sizeof(char));
	len = 0;
	while (&(*str)[len] != exp->start - 1)
		len++;
	ft_strlcpy(new, *str, len + 1);
	ft_strlcat(new, exp->value, size);
	ft_strlcat(new, exp->end, size);
	*str = new;
}

void	expand_str(char **str, t_exp *exp)
{
	int	size;

	if (exp->start == NULL)
		return ;
	size = get_strsize(*str, exp);
	replace_str(str, exp, size);
}
