/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:37:20 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/16 14:13:20 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_list	*get_last_arg(t_list *tokens)
{
	t_list	*previous;

	while (tokens)
	{
		if (token(tokens)->type != WORD)
			break ;
		previous = tokens;
		tokens = tokens->next;
	}
	return (previous);
}

static void	here_first(t_list **tokens)
{
	t_list	*exec;
	t_list	*after;
	t_list	*last_arg;

	if (token(*tokens)->id != HERE_DOC)
		return ;
	exec = (*tokens)->next->next;
	if (exec == NULL)
		return ;
	after = next_operator(exec);
	(*tokens)->next->next = after;
	token(exec)->id = EXEC;
	last_arg = get_last_arg(exec);
	last_arg->next = (*tokens);
	*tokens = exec;
}

/* 
 HERE END
 HERE END EXEC
 HERE END EXEC ARGS

 EXEC ARGS | EXEC ARG1 ARG2 HERE END | ...  
					
 */

void	parse_heredoc(t_list **tokens)
{
	//print_tokens(*tokens);
	here_first(tokens);
	//ft_printf("after here first\n");
	//print_tokens(*tokens);
}

/* 
 EXEC HERE END

 EXEC ARGS HERE END
 
 EXEC HERE END ARGS

 EXEC ARGS HERE END ARGS

 HERE END

 HERE END EXEC

 HERE END EXEC ARGS

 */