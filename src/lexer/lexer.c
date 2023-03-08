/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:15:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/08 14:40:58 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_token(t_token *token)
{
	if (token == NULL)
		return ;
	ft_printf("value: %s\ntype: %d\nid: %d\n", token->value, token->type, token->id);
	free(token);
}

static void	test_functions(char **str)
{
	t_token	*token;

	token = identify_operator(str);
	if (!token)
		token = identify_quotes(str);
	print_token(token);

}

void	lexer(char *str)
{
	t_list	*tokens;

	ft_printf("Lexer started.\n");
	test_functions(&str);
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