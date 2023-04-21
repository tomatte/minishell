/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:34:58 by dbrandao          #+#    #+#             */
/*   Updated: 2023/04/21 16:52:06 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
