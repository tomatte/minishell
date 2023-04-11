/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evar_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:28:51 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/11 17:49:48 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_evar(t_list *node, char *str)
{
	char	*var;
	int		len;

	var = (char *) node->content;
	len = 0;
	while (var[len] && var[len] != '=')
		len++;
	len = ft_highest(len, ft_strlen(str));
	return (ft_strncmp(var, str, len) == 0);
}

t_list	*find_evar2(char *str)
{
	t_list	*vars;

	if (str == NULL)
		return (NULL);
	vars = get_evars2();
	while (vars)
	{
		if (is_evar(vars, str))
			return (vars);
		vars = vars->next;
	}
	return (NULL);
}
