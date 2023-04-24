/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:16:37 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/23 11:07:59 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_var_name(char *full_var)
{
	char	*var_name;
	int		i;

	i = 0;
	while (full_var[i] && full_var[i] != '=')
		i++;
	if (full_var[i] == '\0')
		return (NULL);
	var_name = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(var_name, full_var, i + 1);
	return (var_name);
}

static void	replace_var_value(t_list *var, char *full_var)
{
	free(var->content);
	var->content = (void *) ft_strdup(full_var);
}

static t_list	*find_old_var(char *var_name)
{
	t_list	*var;

	var = find_evar2(var_name);
	return (var);
}

void	add_var_to_evars(char *full_var)
{
	t_list	*var;
	char	*var_name;

	var_name = get_var_name(full_var);
	if (var_name == NULL)
		return ;
	var = find_old_var(var_name);
	if (var)
		replace_var_value(var, full_var);
	else
		add_evar2(full_var);
	free(var_name);
}
