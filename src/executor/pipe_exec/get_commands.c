/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:41:29 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:59 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_list	*first_command(t_list *tokens, int **pipedes)
{
	t_command	*command;

	command = new_command(tokens, STDIN_FILENO, pipedes[0][W]);
	return (lstnew_track(command));
}

static t_list	*new_midcommand(t_list *tokens, int **pipedes, int i)
{
	t_command	*command;

	command = new_command(tokens, pipedes[i - 1][R], pipedes[i][W]);
	return (lstnew_track(command));
}

static void	middle_commands(t_list *tokens, int **pipedes, t_list **commands)
{
	t_list	*new_command;
	int		i;

	tokens = next_pipe(tokens);
	if (tokens == NULL)
		return ;
	tokens = tokens->next;
	i = 1;
	while (next_pipe(tokens))
	{
		new_command = new_midcommand(tokens, pipedes, i++);
		ft_lstadd_back(commands, new_command);
		tokens = next_pipe(tokens)->next;
	}
}

static void	last_command(t_list *tokens, int **pipedes, t_list **commands)
{
	t_command	*command;
	int			i;

	i = 0;
	while (next_pipe(tokens))
	{
		tokens = next_pipe(tokens)->next;
		i++;
	}
	command = new_command(tokens, pipedes[i - 1][R], STDOUT_FILENO);
	ft_lstadd_back(commands, lstnew_track(command));
}

t_list	*get_commands(t_list *tokens, int **pipedes)
{
	t_list	*commands;

	commands = first_command(tokens, pipedes);
	middle_commands(tokens, pipedes, &commands);
	last_command(tokens, pipedes, &commands);
	return (commands);
}
