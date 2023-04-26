/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:58:08 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/26 11:11:56 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	restart(void)
{
	close_pfds();
	close_fds();
	destroy_memories();
}

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
		transformer(str);
		tokens = lexer(str);
		parser(tokens);
		read_docs(tokens);
		executor(tokens);
		restart();
	}
	return (0);
}
