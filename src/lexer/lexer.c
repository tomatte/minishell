/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:15:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/19 19:30:56 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	pass_spaces(char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

static void	add_token(t_list **tokens, char **str)
{
	t_token	*token;

	pass_spaces(str);
	token = identify_operator(str);
	if (token == NULL)
		token = identify_quotes(str);
	if (token == NULL)
		token = identify_word(str);
	if (token == NULL)
		return ;
	ft_lstadd_back(tokens, lstnew_track(token));
}

static void	verify_errors(char **str, t_list **tokens)
{
	if (get_state() <= -1)
	{
		ft_putstr_fd("invalid syntax\n", STDERR_FILENO);
		**str = '\0';
		set_state(1);
		*tokens = NULL;
	}
}

t_list	*lexer(char *str)
{
	t_list	*tokens;

	if (in_error())
		return (NULL);
	tokens = NULL;
	set_state(START);
	while (*str)
	{
		add_token(&tokens, &str);
		verify_errors(&str, &tokens);
	}
	return (tokens);
}
