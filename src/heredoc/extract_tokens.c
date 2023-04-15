/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:39:19 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/15 14:13:41 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_line_len(char *text)
{
	int	len;

	len = 0;
	while (text[len] && text[len] != '\n')
		len++;
	if (text[len] == '\n')
		len++;
	return (len);
}

static void	pass_line(char **text)
{
	while (**text && **text != '\n')
		(*text)++;
	if (**text)
		(*text)++;
}

t_list	*extract_tokens(char *text)
{
	t_list	*args;
	t_token	*arg;
	char	*line;
	int		len;

	if (in_error())
		return (NULL);
	args = NULL;
	len = 0;
	while (*text)
	{
		len = get_line_len(text);
		line = ft_calloc(len + 1, sizeof(char));
		ft_strlcpy(line, text, len + 1);
		arg = new_token(line, WORD, ARG);
		ft_lstadd_back(&args, lstnew_track(arg));
		pass_line(&text);
	}
	return (args);
}
