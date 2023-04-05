/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:47:44 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/05 12:19:00 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_pipedes(int **pipedes)
{
	while (*pipedes)
	{
		ft_printf("r%d / w%d\n", (*pipedes)[0], (*pipedes)[1]);
		pipedes++;
	}
}

void	print_command(t_command *command)
{
	int	i;

	ft_printf("COMMAND %s\n", command->args[0]);
	ft_printf("args: ");
	i = -1;
	while (command->args[++i])
		ft_printf("%s   ", command->args[i]);
	ft_printf("\ninput_fd: %d\n", command->input_fd);
	ft_printf("output_fd: %d\n", command->output_fd);
	ft_printf("status: %d\n", command->status);
}

void	print_commands(t_list *commands)
{
	while (commands)
	{
		print_command((t_command *) commands->content);
		commands = commands->next;
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

void	print_tokens(t_list *tokens)
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

void	print_args(char **args)
{
	int	i;

	ft_printf("Args:");
	i = -1;
	while (args[++i])
		ft_printf("  %s", args[i]);
	ft_printf("\n");
}
