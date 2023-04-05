/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:58:08 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/05 10:28:38 by dbrandao         ###   ########.fr       */
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

static void	print_error(void)
{
	if (get_state())
		ft_printf("THERE'S AN ERROR! Code: %d\n", get_state());
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

// ---- ANY CODE TO BE TESTED --- //
static void	test_some_code(t_list *tokens)
{
	int	redirects[2];

	get_redirects(tokens, redirects);
	ft_printf("RR: %d\nRW: %d\n", redirects[R], redirects[W]);
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_list	*tokens;

	(void) argv;
	(void) argc;
	start_evars(envp);
	while (1)
	{
		str = prompt();
		is_exit(str);
		expander(&str);
		tokens = lexer(str);
		parser(tokens);
		executor(tokens);
		print_error();
		destroy_memories();
	}
	return (0);
}
