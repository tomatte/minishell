/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:59:05 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/18 13:59:14 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_list	*get_left_token(t_list	*tokens)
{
	t_list	*here;

	here = find_heredoc(tokens);
	if (tokens == here)
		return (NULL);
	while (tokens)
	{
		if (tokens->next == here)
			return (tokens);
		tokens = tokens->next;
	}
	return (NULL);
}

static int	is_cmd_left(t_list *node)
{
	if (node == NULL)
		return (0);
	if (token(node)->id == HERE_DOC_END)
		return (0);
	return (token(node)->type == WORD);
}

static t_list	*get_cmd_left(t_list *tokens)
{
	t_list	*cmd;

	cmd = tokens;
	while (tokens)
	{
		if (token(tokens)->id == PIPE)
			cmd = tokens->next;
		if (token(tokens)->id == HERE_DOC)
			break ;
		tokens = tokens->next;
	}
	return (cmd);
}

static t_list	*get_cmd_right(t_list *tokens)
{
	t_list	*here;
	t_list	*cmd;

	here = find_heredoc(tokens);
	cmd = here->next->next;
	if (cmd == NULL)
		return (NULL);
	if (token(cmd)->id != ARG)
		return (NULL);
	return (cmd);
}

t_list	*get_heredoc_cmd(t_list *tokens)
{
	t_list	*here;
	t_list	*left_token;
	t_list	*cmd;

	here = find_heredoc(tokens);
	left_token = get_left_token(tokens);
	if (is_cmd_left(left_token))
		cmd = get_cmd_left(tokens);
	else
		cmd = get_cmd_right(tokens);
	return (cmd);
}
