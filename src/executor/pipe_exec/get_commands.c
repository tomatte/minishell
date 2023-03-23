/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:41:29 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/23 14:54:40 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static t_list	*first_command(t_list *tokens, int **pipedes)
{
	t_command	*command;

	command = ft_calloc(1, sizeof(t_command));
	command->args = get_args(tokens);
	command->input_fd = STDIN_FILENO;
	command->output_fd = pipedes[0][R];
	return (ft_lstnew(command));
}

static void	print_command(t_command *command)
{
	int	i;

	ft_printf("COMMAND %s\n", command->args[0]);
	ft_printf("args: ");
	i = -1;
	while (command->args[++i])
		ft_printf("%s   ", command->args[i]);
	ft_printf("\ninput_fd: %d\n", command->input_fd);
	ft_printf("output_fd: %d\n", command->output_fd);
	ft_printf("status: %d\n", command->status);
}

t_list	*get_commands(t_list *tokens, int **pipedes)
{
	t_list	*commands;

	commands = first_command(tokens, pipedes);
	print_command((t_command *) commands->content);
	return (NULL);
}
