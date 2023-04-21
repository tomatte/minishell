/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:18:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/21 17:24:48 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	remove_quotes(char *str, char **end)
{
	char	*dst;
	char	quote;
	int		i;

	quote = 0;
	dst = str;
	i = 0;
	while (str <= *end)
	{
		if ((is_quote(*str) && !quote))
			quote = *str++;
		else if (*str == quote)
			quote = (0 * (*str++));
		else
			dst[i++] = *str++;
	}
	*end = &(dst[i]);
	while (*str)
		dst[i++] = *str++;
	dst[i] = '\0';
}

static char	*get_end_of_word(char *s)
{
	s++;
	while (*s && !is_delimiter2(*s))
	{
		pass_quotes(&s);
		s++;
	}
	return (s - 1);
}

static void	join_word(char **str)
{
	char	*s;
	char	quote;
	char	*end;

	s = get_opening_quote(*str);
	quote = *s;
	move_quote_left(s, *str);
	s = get_closing_quote(s, quote);
	end = get_end_of_word(s);
	remove_quotes(s + 1, &end);
	move_quote_right(s, str, end);
	
}

static void	transform_word(char **str)
{
	if (!have_quotes(*str))
		pass_word(str);
	else
		join_word(str);
}

void	transformer(char *str)
{
	while (*str)
	{
		if (!is_delimiter2(*str))
			transform_word(&str);
		else
			str++;
	}
}
