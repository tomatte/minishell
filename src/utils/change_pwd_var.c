/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pwd_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:35:33 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/25 21:46:19 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	change_pwd_var(char *var)
{
	char	*pwd;
	char	*dir;

	dir = getcwd(NULL, 0);
	add_to_tracker(dir);
	pwd = ft_strjoin(var, dir);
	add_to_tracker(pwd);
	add_var_to_evars(pwd);
}
