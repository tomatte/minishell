/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:20:33 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/14 10:53:30 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_option(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '-')
		str++;
	else
		return (0);
	if (*str == '-')
		str++;
	if (*str)
		return (1);
	return (0);
}
