/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:58:08 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/29 09:38:13 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	is_exit(char *str)
{
	if (ft_strncmp(str, "exit", 5) == 0)
	{
		destroy_memories();
		destroy_evars();
		rl_clear_history();
		exit(0);
	}
}

static void	print_token(t_token *token)
{
	char	*CONSTANTS[] = {"NONE", "START", "WORD", "OPERATOR", "EXPANSIVE", \
	"QUOTE", "EXEC", "ARG", "IN_FILE", "OUT_FILE", "HERE_DOC_END", \
	"SIMPLE_QUOTES", "DOUBLE_QUOTES", "ENV_VAR", "EXIT_STAT", "HERE_DOC", \
	"R_APPEND_OUT", "R_INPUT", "R_OUTPUT", "PIPE"};

	ft_printf("[%s]  ", CONSTANTS[token->id]);
}

static void	print_tokens(t_list *tokens)
{
	if (!tokens)
		ft_printf("\n");
	while (tokens)
	{
		print_token(tokens->content);
		tokens = tokens->next;
	}
	ft_printf("\n");
}

static void	print_error(void)
{
	if (get_state() < 0)
		ft_printf("THERE'S AN ERROR!\n");
}

static void	print_evars()
{
	char	**evars;

	evars = get_evars();
	while (*evars)
	{
		ft_printf("%s\n", *evars);
		evars++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_list	*tokens;

	(void) argv;
	(void) argc;
	while (1)
	{
		str = prompt();
		is_exit(str);
		tokens = lexer(str);
		parser(tokens);
		executor(tokens, envp);
		print_error();
		destroy_memories();
	}
	return (0);
}
