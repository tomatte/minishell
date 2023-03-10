/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:15:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/10 15:42:41 by dbrandao         ###   ########.fr       */
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
	{
		pass_spaces(str);
		token = identify_quotes(str);
	}	
	if (token == NULL)
	{
		pass_spaces(str);
		token = identify_word(str);
	}
	if (token == NULL)
		return ;
	ft_lstadd_back(tokens, ft_lstnew(token));
}

static void	veirify_errors(char **str, t_list **tokens)
{
	if (get_state() <= -1)
	{
		ft_printf("Error\n");
		**str = '\0';
		//clear_tokens(tokens)
		set_state(1);
		*tokens = NULL;
	}
	if (**str == '$')
	{
		ft_printf("Should treat dolar sign $\n");
		(*str)++;
	}
}

t_list	*lexer(char *str)
{
	t_list	*tokens;

	tokens = NULL;
	ft_printf("Lexer started.\n");
	set_state(START);
	while (*str)
	{
		add_token(&tokens, &str);
		veirify_errors(&str, &tokens);
	}
	return (tokens);
}

/* 
caso um token seja identificado:
	criar um novo nó do tipo token
		value = "string referente ao token"
		type = tipo do token
		id = o id do token relacionado ao seu tipo
	avançar o ponteiro da string

exemplo
	OPERATOR identificado.
	token = new_token()
	token->value = "|"
	token->type = OPERATOR
	token->id = PIPE

	str += ft_strlen(token->value)
 */