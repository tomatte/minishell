/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:29:57 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_command	*new_command(t_list *tokens, int fd_in, int fd_out)
{
	t_command	*command;

	command = talloc(1, sizeof(t_command));
	command->args = get_args(tokens);
	command->input_fd = fd_in;
	command->output_fd = fd_out;
	return (command);
}
