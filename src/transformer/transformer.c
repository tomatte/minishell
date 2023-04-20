/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:18:54 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/20 17:52:14 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_delimiter(char c)
{
	if (ft_strchr(DELIMITER2, c))
		return (1);
	if (ft_isspace(c))
		return (1);
	return (0);
}

static int	is_quote(char c)
{
	if (c == '"' || c == '\'')
		return (1);
	return (0);
}

static int	have_quotes(char *s)
{
	while (*s)
	{
		if (is_quote(*s))
			return (1);
		if (is_delimiter(*s))
			return (0);
		s++;
	}
	return (0);
}

static void	pass_word(char **str)
{
	while (**str && !is_delimiter(**str))
		(*str)++;
}

static void	move_quote_left(char *str, char *start)
{
	char	c;

	while (str > start)
	{
		c = *(str - 1);
		*(str - 1) = *str;
		*str = c;
		str--;
	}
}

static char	*get_opening_quote(char *str)
{
	while (*str && !is_quote(*str))
		str++;
	return (str);
}

static char	*get_closing_quote(char *s, char quote)
{
	s++;
	while (*s != quote)
		s++;
	return (s);
}

static void	move_quote_right(char *s, char **str)
{
	char	c;
	char	*end;

	end = s;
	while (*(end + 1) && !is_delimiter(*(end + 1)))
		end++;
	while (s < end)
	{
		c = *(s + 1);
		*(s + 1) = *s;
		*s = c;
		s++;
	}
	*str = (end + 1);
}

static void	join_word(char **str)
{
	char	*s;
	char	quote;

	s = get_opening_quote(*str);
	quote = *s;
	move_quote_left(s, *str);
	s = get_closing_quote(s, quote);
	move_quote_right(s, str);
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
		if (!is_delimiter(*str))
			transform_word(&str);
		str++;
	}
	ft_printf("aquiiiiiii\n");
}

/*  

'abc'efd
abc'efd'
abc'efd'gc

e|'abc'efd

*/