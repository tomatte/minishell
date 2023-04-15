/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:37:08 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/15 16:47:49 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*prompt(void)
{
	char	*str_command;
	char	*msg;

	msg = get_prompt_msg();
	str_command = readline(msg);
	if (str_command == NULL)
	{
		ft_printf("exit\n");
		mini_exit(get_error());
	}
	free(msg);
	add_history(str_command);
	add_to_tracker(str_command);
	return (str_command);
}
