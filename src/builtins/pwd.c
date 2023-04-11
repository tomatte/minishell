/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:30:52 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/11 14:47:19 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd(void)
{
	char	dir[256];

	getcwd(dir, 256);
	if (dir == NULL)
		ft_printf("too big directory name\n");
	else
		ft_printf("%s\n", dir);
}
