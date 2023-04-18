/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:58:08 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/18 10:22:19 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_list	*tokens;

	(void) argv;
	(void) argc;
	start_evars2(envp);
	while (1)
	{
		set_signals();
		str = prompt();
		expander(&str);
		tokens = lexer(str);
		parser(tokens);
		print_tokens(tokens);
		heredoc_operation(&tokens);
		executor(tokens);
		destroy_memories();
	}
	return (0);
}
