/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:58:08 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/14 22:27:24 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* static void	print_evars()
{
	char	**evars;

	evars = get_evars();
	while (*evars)
	{
		ft_printf("%s\n", *evars);
		evars++;
	}
} */

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_list	*tokens;

	(void) argv;
	(void) argc;
	start_evars2(envp);
	while (1)
	{
		str = prompt();
		expander(&str);
		tokens = lexer(str);
		parser(tokens);
		executor(tokens);
		destroy_memories();
	}
	return (0);
}
