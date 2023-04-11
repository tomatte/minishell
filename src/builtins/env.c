/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:58:26 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/11 15:03:24 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env(void)
{
	char	**envs;

	envs = get_evars();
	if (envs == NULL)
		return ;
	while (*envs)
		ft_printf("%s\n", *envs++);
}
