/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:15:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/08 17:30:53 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_token(t_token *token)
{
	if (token == NULL)
		return ;
	ft_printf("value: %s\n", token->value);
	if (token->type == WORD)
		ft_printf("type: WORD\n");
	else if (token->type == OPERATOR)
		ft_printf("type: OPERATOR\n");
	else if (token->type == QUOTE)
		ft_printf("type: QUOTE\n");
	ft_printf("id: %d\n", token->id);
	free(token);
}

static void	test_functions(char **str)
{
	t_token	*token;

	token = identify_operator(str);
	if (!token)
		token = identify_quotes(str);
	if (token == NULL)
		token = identify_word(str);
	print_token(token);

}

static void	pass_spaces(char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

static void	add_token(t_list **tokens, char **str)
{
	t_token	*token;

	pass_spaces(str);
	token = token = identify_operator(str);
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

static void	print_tokens(t_list *tokens)
{
	if (!tokens)
		ft_printf("null\n");
	while (tokens)
	{
		ft_printf("\n\n--- TOKEN ---\n");
		print_token(tokens->content);
		tokens = tokens->next;
	}
}

void	lexer(char *str)
{
	t_list	*tokens;

	tokens = NULL;
	ft_printf("Lexer started.\n");
	while (*str)
		add_token(&tokens, &str);
	print_tokens(tokens);
	ft_printf("s: %s\n", str);
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