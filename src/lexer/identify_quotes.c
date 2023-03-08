/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:34:58 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/08 14:39:27 by dbrandao         ###   ########.fr       */
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

t_token	*identify_quotes(char **str)
{
	char	*value;
	int		id;

	if (*str == NULL)
		return (NULL);
	id = get_quote_id(*str);
	if (id == -1)
		return (NULL);
	value = get_value(*str);
	if (value == NULL)
		return (NULL);
	(*str) += ft_strlen(value) + 2;
	return (new_token(value, QUOTE, id));
}
