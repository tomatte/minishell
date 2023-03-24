/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:41:29 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/24 12:21:34 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static t_list	*first_command(t_list *tokens, int **pipedes)
{
	t_command	*command;

	command = ft_calloc(1, sizeof(t_command));
	command->args = get_args(tokens);
	command->input_fd = STDIN_FILENO;
	command->output_fd = pipedes[0][W];
	return (ft_lstnew(command));
}

static t_list	*new_midcommand(t_list *tokens, int **pipedes, int i)
{
	t_command	*command;

	command = ft_calloc(1, sizeof(t_command));
	if (command == NULL)
		return (NULL);
	command->args = get_args(tokens);
	command->input_fd = pipedes[i - 1][R];
	command->output_fd = pipedes[i][W];
	return (ft_lstnew(command));
}

static void	middle_commands(t_list *tokens, int **pipedes, t_list **commands)
{
	t_list	*new_command;
	int		i;

	tokens = next_operator(tokens)->next;
	i = 1;
	while (is_operator(next_operator(tokens), PIPE))
	{
		new_command = new_midcommand(tokens, pipedes, i++);
		ft_lstadd_back(commands, new_command);
		tokens = next_operator(tokens)->next;
	}
}

static void	last_command(t_list *tokens, int **pipedes, t_list **commands)
{
	t_command	*command;
	int			i;

	i = 0;
	while (is_operator(next_operator(tokens), PIPE))
	{
		tokens = next_operator(tokens)->next;
		i++;
	}
	command = ft_calloc(1, sizeof(t_command));
	command->args = get_args(tokens);
	command->input_fd = pipedes[i - 1][R];
	command->output_fd = STDOUT_FILENO;
	ft_lstadd_back(commands, ft_lstnew(command));
}

t_list	*get_commands(t_list *tokens, int **pipedes)
{
	t_list	*commands;

	commands = first_command(tokens, pipedes);
	middle_commands(tokens, pipedes, &commands);
	last_command(tokens, pipedes, &commands);
	return (commands);
}
