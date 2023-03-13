/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   categorize_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:53:14 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/13 16:30:34 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_exec(t_token *token)
{
	int	s;

	s = get_state();
	if (s == START || s == PIPE)
	{
		set_state(EXEC);
		token->id = EXEC;
		return (1);
	}
	return (0);
}

static int	is_infile(t_token *token)
{
	int	s;

	s = get_state();
	if (s == R_INPUT)
	{
		set_state(IN_FILE);
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
		set_state(OUT_FILE);
		token->id = OUT_FILE;
		return (1);
	}
	return (0);
}

static int	is_heredoc_end(t_token *token)
{
	if (get_state() == HERE_DOC)
	{
		set_state(HERE_DOC_END);
		token->id = HERE_DOC_END;
		return (1);
	}
	return (0);
}

void	categorize_word(t_token *token)
{
	if (token->type != WORD && token->type != QUOTE)
		return ;
	if (is_exec(token))
		;
	else if (is_infile(token))
		;
	else if (is_outfile(token))
		;
	else if (is_heredoc_end(token))
		;
	else
		token->id = ARG;
}
