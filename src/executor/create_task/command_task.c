/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_task.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:54:17 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/15 18:00:17 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	is_command_task(t_list *tokens)
{
	t_token	*token;

	token = (t_token *) tokens->content;
	return (token->id == EXEC);
}

static int	get_args_len(t_list *tokens)
{
	t_token	*token;
	int		len;

	len = 1;
	tokens = tokens->next;
	while (tokens)
	{
		token = (t_token *) tokens->content;
		if (token->id == ARG)
			len++;
		else if (token->id == EXEC)
			break ;
		tokens = tokens->next;
	}
	return (len);
}

static char	**get_args(t_list *tokens)
{
	t_token	*token;
	char	**args;
	int		len;
	int		i;

	len = get_args_len(tokens);
	args = (char **) malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (tokens && i < len)
	{
		token = (t_token *) tokens->content;
		if (token->id == ARG || token->id == EXEC)
			args[i++] = token->value;
		tokens = tokens->next;
	}
	args[len] = NULL;
	return (args);
}

void	command_task(t_task *task, t_list *tokens)
{
	if (!is_command_task(tokens))
		return ;
	task->type = EXEC;
	task->args = get_args(tokens);
}
