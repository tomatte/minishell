/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:37:08 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/27 16:16:13 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*prompt(void)
{
	char	*str_command;
	char	*msg;

	msg = get_prompt_msg();
	str_command = readline(msg);
	free(msg);
	add_history(str_command);
	add_to_tracker(str_command);
	return (str_command);
}
