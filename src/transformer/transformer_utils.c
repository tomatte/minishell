/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:58:53 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/24 22:44:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_quote(char c)
{
	if (c == '"' || c == '\'')
		return (1);
	return (0);
}

int	is_delimiter2(char c)
{
	if (ft_strchr(DELIMITER2, c))
		return (1);
	if (ft_isspace(c))
		return (1);
	return (0);
}

int	have_quotes(char *s)
{
	while (*s)
	{
		if (is_quote(*s))
			return (1);
		if (is_delimiter2(*s))
			return (0);
		s++;
	}
	return (0);
}

void	pass_word(char **str)
{
	while (**str && !is_delimiter2(**str))
		(*str)++;
}

void	pass_quotes(char **s)
{
	char	quote;

	if (is_quote(**s))
	{
		quote = **s;
		(*s)++;
		while (**s != quote)
			(*s)++;
		quote = 0;
	}
}
