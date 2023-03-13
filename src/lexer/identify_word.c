/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:08:39 by dbrandao          #+#    #+#             */
/*   Updated: 2023/03/08 17:08:09 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_delimiter(char c)
{
	if (ft_strchr(DELIMITER, c))
		return (1);
	if (ft_isspace(c))
		return (1);
	return (0);
}

static int	get_word_size(char *str)
{
	int	i;

	i = 0;
	while (!is_delimiter(str[i]))
		i++;
	return (i);
}

t_token	*identify_word(char **str)
{
	char	*value;
	int		size;

	size = get_word_size(*str);
	if (size == 0)
		return (NULL);
	size++;
	value = (char *) malloc(sizeof(char) * size);
	ft_strlcpy(value, *str, size);
	(*str) += size - 1;
	return (new_token(value, WORD, -1));
}
