/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   categorize_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:53:14 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/19 10:38:03 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_exec(t_token *token)
{
	int	s;

	s = get_state();
	if (s >= IN_FILE && s <= HERE_DOC_END)
		token->id = EXEC;
	else if (s == START || s == PIPE)
		token->id = EXEC;
	else
		return (0);
	return (1);
}

static int	is_infile(t_token *token)
{
	int	s;

	s = get_state();
	if (s == R_INPUT)
	{
		token->id = IN_FILE;
		return (1);
	}
	return (0);
}

static int	is_outfile(t_token *token)
{
	int	s;

	s = get_state();
	if (s == R_OUTPUT || s == R_APPEND_OUT)
	{
		token->id = OUT_FILE;
		return (1);
	}
	return (0);
}

static int	is_heredoc_end(t_token *token)
{
	if (get_state() == HERE_DOC)
	{
		token->id = HERE_DOC_END;
		return (1);
	}
	return (0);
}

void	categorize_word(t_token *token)
{
	if (token->type != WORD && token->type != QUOTE)
		return ;
	if (is_heredoc_end(token))
		set_state(HERE_DOC_END);
	else if (is_infile(token))
		set_state(IN_FILE);
	else if (is_outfile(token))
		set_state(OUT_FILE);
	else if (is_exec(token))
		set_state(EXEC);
	else
		token->id = ARG;
}
