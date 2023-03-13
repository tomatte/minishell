/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nut_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:47:29 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/13 15:26:27 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//nut == Near Unexpected Token
void	nut_error(char *str)
{
	ft_putstr_fd("bash: syntax error near unexpected token `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("'\n", 2);
	set_state(ERR_NUT);
}
