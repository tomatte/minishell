/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:14:23 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	get_args_len(t_list *tokens)
{
	t_token	*token;
	int		len;

	len = 1;
	tokens = tokens->next;
	while (tokens)
	{
		token = (t_token *) tokens->content;
		if (token->id == ARG)
			len++;
		else if (token->id == EXEC)
			break ;
		tokens = tokens->next;
	}
	return (len);
}

char	**get_args(t_list *tokens)
{
	t_token	*token;
	char	**args;
	int		len;
	int		i;

	len = get_args_len(tokens);
	args = (char **) talloc(len + 1, sizeof(char *));
	i = 0;
	while (tokens && i < len)
	{
		token = (t_token *) tokens->content;
		if (token->id == ARG || token->id == EXEC)
			args[i++] = token->value;
		tokens = tokens->next;
	}
	args[len] = NULL;
	return (args);
}
