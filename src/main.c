/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:58:08 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/09 15:45:13 by dbrandao         ###   ########.fr       */
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

int	main(int argc, char const *argv[])
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
		free(str);
	}
	return (0);
}
