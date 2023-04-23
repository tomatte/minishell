/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:16:37 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/23 10:22:13 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_var_name(char *full_var)
{
	char	*var_name;
	int		i;

	i = 0;
	while (full_var[i] != '=')
		i++;
	var_name = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(var_name, full_var, i + 1);
	return (var_name);
}

void	export_evar(char *full_var)
{
	char	*var_name;

	var_name = get_var_name(full_var);
	ft_printf("var_name: %s\n", var_name);
}
