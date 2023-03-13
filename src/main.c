/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:58:08 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/13 17:07:47 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	is_exit(char *str)
{
	if (ft_strncmp(str, "exit", 5) == 0)
	{
		free(str);
		rl_clear_history();
		exit(0);
	}
}

static void	test_function(void)
{
	int	i;

	i = -1;
	while (++i < 5)
		ft_printf("%s\t", operators()[i]);
	ft_printf("\n");

	printf("s: %d\t", get_state());
	set_state(1);
	printf("s: %d\t", get_state());
	printf("s: %d\t", get_state());
	set_state(5);
	printf("s: %d\t", get_state());
	set_state(-1);
	printf("s: %d\n", get_state());
}

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
	if (token->id == EXEC)
		ft_printf("id: EXEC\n");
	else if (token->id == ARG)
		ft_printf("id: ARG\n");
	else if (token->id == IN_FILE)
		ft_printf("id: IN_FILE\n");
	else if (token->id == OUT_FILE)
		ft_printf("id: OUT_FILE\n");
	else if (token->id == HERE_DOC_END)
		ft_printf("id: HERE_DOC_END\n");
	else
		ft_printf("id: %d\n", token->id);
}

static void	print_tokens(t_list *tokens)
{
	if (!tokens)
		ft_printf("\n");
	while (tokens)
	{
		ft_printf("\n\n--- TOKEN ---\n");
		print_token(tokens->content);
		tokens = tokens->next;
	}
}

static void	print_error(void)
{
	if (get_state() < 0)
		ft_printf("SYNTAX ERROR!\n");
}

int	main(void)
{
	char	*str;
	t_list	*tokens;

	test_function();
	while (1)
	{
		str = prompt();
		is_exit(str);
		tokens = lexer(str);
		parser(tokens);
		executor(tokens);
		print_tokens(tokens);
		print_error();
		cleaner(str, tokens);
	}
	return (0);
}
