/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_exp_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:54:22 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/13 14:17:14 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_evar_eq(char *evar, char *name)
{
	int	len;

	len = 0;
	while (evar[len] != '=')
		len++;
	len = ft_highest(len, ft_strlen(name));
	return (ft_strncmp(evar, name, len) == 0);
}

static char	*find_evar(t_exp *exp)
{
	char	**evars;

	evars = get_evars_arr();
	while (*evars)
	{
		if (is_evar_eq(*evars, exp->name))
			break ;
		evars++;
	}
	return (*evars);
}

static char	*extract_value(char *evar)
{
	char	*new;

	while (*evar != '=')
		evar++;
	new = ft_strdup(evar + 1);
	add_to_tracker(new);
	return (new);
}

static char	*strdup_track(char *str)
{
	char	*new;

	new = ft_strdup(str);
	add_to_tracker(new);
	return (new);
}

void	fill_exp_value(t_exp *exp)
{
	char	*evar;

	if (exp->start == NULL)
	{
		exp->value = strdup_track("");
		return ;
	}
	if (*exp->start == '?')
	{
		exp->value = ft_itoa(get_error());
		return ;
	}
	evar = find_evar(exp);
	if (evar == NULL)
	{
		exp->value = strdup_track("");
		return ;
	}
	exp->value = extract_value(evar);
}
