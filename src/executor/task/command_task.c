/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_task.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:54:17 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/15 14:40:26 by dbrandao         ###   ########.fr       */
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

static void	fill_args(t_task *task, t_list *tokens)
{
	int	len;

	len = get_args_len(tokens);
	ft_printf("t_arg_len: %d\n", len);
}

void	command_task(t_task *task, t_list *tokens)
{
	if (!is_command_task(tokens))
		return ;
	fill_args(task, tokens);
}
