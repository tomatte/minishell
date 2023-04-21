/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:34:58 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/21 15:29:46 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_quote_id(char *str)
{
	if (*str == '"')
		return (SIMPLE_QUOTES);
	else if (*str == '\'')
		return (DOUBLE_QUOTES);
	else
		return (-1);
}

static int	get_value_size(char *str)
{
	char	quote;
	int		i;

	quote = *str;
	i = 1;
	while (str[i])
	{
		if (str[i] == quote)
			break ;
		i++;
	}
	if (str[i] == '\0')
		return (ERR_UNCLOSED_QUOTES);
	return (i);
}

static int	is_unclosed_quote(int size)
{
	if (size == ERR_UNCLOSED_QUOTES)
	{
		set_state(ERR_UNCLOSED_QUOTES);
		return (1);
	}
	return (0);
}

static char	*get_value(char *str)
{
	char	*value;
	int		size;

	size = get_value_size(str);
	if (is_unclosed_quote(size))
		return (NULL);
	value = (char *) malloc(sizeof(char) * size);
	str++;
	ft_strlcpy(value, str, size);
	return (value);
}

static int	is_delimiter(char c)
{
	if (ft_strchr(DELIMITER2, c))
		return (1);
	if (ft_isspace(c))
		return (1);
	return (0);
}

static char	*get_value2(char *str)
{
	char	*word;
	int		len;

	str++;
	len = 0;
	while (str[len] != UNIT_SEPARATOR)
		len++;
	word = ft_calloc(len + 1, sizeof(char));
	ft_memmove(word, str, len);
	word[len] = '\0';
	return (word);
}

static void	jump_addr(char **str)
{
	if (**str == UNIT_SEPARATOR)
		(*str)++;
	while (**str != UNIT_SEPARATOR)
		(*str)++;
	(*str)++;
}

t_token	*identify_quotes(char **str)
{
	char	*value;

	if (*str == NULL)
		return (NULL);
	if (**str != UNIT_SEPARATOR)
		return (NULL);
	value = get_value2(*str);
	jump_addr(str);
	return (new_token(value, QUOTE, DOUBLE_QUOTES));
}
